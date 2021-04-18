#pragma once

#include<queue>
#include "bst.hpp"

template<typename T>
void move_all(std::vector<T>& v1, std::vector<T>&& v2) {
    v1.insert(v1.end(), std::move_iterator(v2.begin()), std::move_iterator(v2.end()));
}

int node_sum(std::vector<int> values, int begin, int end);

std::vector<std::vector<int>> balanced_choices_helper(int size, int nodes, int max_nodes,
        std::vector<int> starting_vec, int index);

std::vector<std::vector<int>> balanced_choices(int size, int total_nodes);

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

template<typename T>
bool symmetric_helper(const Tree<T>* tree, const Tree<T>* mirror) {
    if (tree->left && mirror->right && symmetric_helper(tree->left.get(), mirror->right.get())) {
        if (tree->right && mirror->left)
            return symmetric_helper(tree->right.get(), mirror->left.get());
        if (!(tree->right) && !(mirror->left))
            return true;
        return false;
    }
    if (!(tree->left) && !(mirror->right)) {
        if (tree->right && mirror->left)
            return symmetric_helper(tree->right.get(), mirror->left.get());
        if (!(tree->right) && !(mirror->left))
            return true;
        return false;
    }
    return false;
}

template<typename T>
bool symmetric(const Tree<T>* tree) {
    if (!tree)
        return true;
    if (tree->left && tree->right)
        return symmetric_helper(tree->left.get(), tree->right.get());
    if (!(tree->left) && !(tree->right))
        return true;
    return false;
}