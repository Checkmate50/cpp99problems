#include<vector>
#include "bst_functions.hpp"

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
        difflow = std::min(difflow, diff);
        diffhigh = std::max(diffhigh, diff);
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