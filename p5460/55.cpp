#include <queue>
#include "bst.hpp"
#include "print.hpp"

template<typename T>
void move_all(std::vector<T>& v1, std::vector<T>&& v2) {
    v1.insert(v1.end(), std::move_iterator(v2.begin()), std::move_iterator(v2.end()));
}

int node_sum(std::vector<int> values, int begin, int end) {
    int result = 0;
    for (int i = begin; i < end; i++)
        result += ((values[i] >> 1) & 1) + (values[i] & 1);
    return result;
}

std::vector<std::vector<int>> balanced_choices_helper(int size, int nodes, int max_nodes,
        std::vector<int> starting_vec, int index) {
    std::vector<std::vector<int>> result;
    if (index >= size >> 1) {
        if (nodes == max_nodes)
            result.push_back(starting_vec);
        return result;
    }
    std::vector<int> next_try;
    int difflow = 1;
    int diffhigh = 1;
    // Get the most imbalanced "branch" of the current node
    // If there's a conflict in imbalance (no viable solutions), reject this path
    int begin = index - 1;
    int end = index;
    int offset = 2;
    for (int num = index; num & 1; num >>= 1) {
        int lsum = node_sum(starting_vec, begin, end);
        int rsum = node_sum(starting_vec, end, index);
        int diff = lsum - rsum;
        begin -= offset;
        end -= offset >> 1;
        offset <<= 1;
        if (difflow > diff)
            difflow = diff;
        if (diffhigh < diff)
            diffhigh = diff;
        if (difflow <= -2 || diffhigh >= 4)
            break;
    }
    // check the current imbalence level
    if (diffhigh <= 1 && difflow >= -1) {
        next_try = starting_vec;
        next_try.push_back(0);
        move_all(result, balanced_choices_helper(size, nodes, max_nodes, next_try, index + 1));
    }
    if (diffhigh <= 2 && difflow >= 0) {
        if (nodes < max_nodes) {
            next_try = starting_vec;
            next_try.push_back(1);
            move_all(result, balanced_choices_helper(size, nodes + 1, max_nodes, next_try, index + 1));

            next_try = starting_vec;
            next_try.push_back(2);
            move_all(result, balanced_choices_helper(size, nodes + 1, max_nodes, next_try, index + 1));
        }
    }

    if (diffhigh <= 3 && difflow >= 1) {
        if (nodes < max_nodes - 1) {
            next_try = starting_vec;
            next_try.push_back(3);
            move_all(result, balanced_choices_helper(size, nodes + 2, max_nodes, next_try, index + 1));
        }
    }

    return result;
}

std::vector<std::vector<int>> balanced_choices(int size, int total_nodes) {
    int nodes = (total_nodes + 1) ^ (1 << size >> 1);
    if (!nodes) {
        std::vector<std::vector<int>> result;
        return result;
    }
    std::vector<int> empty;
    return balanced_choices_helper((1 << size >> 1), 0, nodes, empty, 0);
}

template<typename T>
std::vector<tree_ptr<T>> cbal_tree(int nodes, T val) {
    std::vector<tree_ptr<T>> result;
    if (nodes <= 0)
        return result;
    int max_nodes_bit = 0;
    // Get the max node bit, which determines the level of the resulting tree
    for (int nodes_counter = nodes + 1; nodes_counter > 0; nodes_counter >>= 1)
        max_nodes_bit++;

    auto balanced = balanced_choices(max_nodes_bit, nodes);
    pve(balanced);
    std::vector<std::unique_ptr<std::queue<tree_ptr<T>>>> leaves;
    if (balanced.size() == 0) {
        leaves.push_back(std::make_unique<std::queue<tree_ptr<T>>>());
        for (int i = 0; i < ((1 << (max_nodes_bit - 1)) >> 1); i++)
            leaves[0]->push(std::make_unique<Tree<T>>(val, nullptr, nullptr));
    }
    for (int i = 0; i < balanced.size(); i++)
        leaves.push_back(std::make_unique<std::queue<tree_ptr<T>>>());

    for (int i = 0; i < balanced.size(); i++) {
        for (auto& branch : balanced[i]) {
            auto leaf_left = std::make_unique<Tree<T>>(val, nullptr, nullptr);
            auto leaf_right = std::make_unique<Tree<T>>(val, nullptr, nullptr);
            if (!(branch & 1))
                leaf_left = nullptr;
            if (!(branch & 2))
                leaf_right = nullptr;
            leaves[i]->push(std::make_unique<Tree<T>>(val, std::move(leaf_left), std::move(leaf_right)));
        }
    }
    // Note the >> 1 to make the counting magic work
    for (int level = (1 << max_nodes_bit) >> 3; level > 0; level >>= 1) {
        for (int i = 0; i < level; i++) {
            for (int j = 0; j < leaves.size(); j++) {
                auto leaf1 = std::move(leaves[j]->front());
                leaves[j]->pop();
                auto leaf2 = std::move(leaves[j]->front());
                leaves[j]->pop();
                leaves[j]->push(std::make_unique<Tree<T>>(val, std::move(leaf1), std::move(leaf2)));
            }
        }
    }
    for (int i = 0 ; i < leaves.size(); i++)
        result.push_back(std::move(leaves[i]->front()));
    return result;
}

std::vector<tree_ptr<char>> cbal_tree(int nodes) {
    return cbal_tree(nodes, 'x');
}

int main() {
    pve(cbal_tree(23));
}