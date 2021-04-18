#include "bst.hpp"
#include "print.hpp"
#include "bst_functions.hpp"
#include<iostream>

// Write a predicate to construct a binary search tree from a list of integer numbers.
// Then use this predicate to test the solution of the problem P56.

template<typename T>
tree_ptr<T> add(tree_ptr<T> tree, T val) {
    if (!tree)
        return std::make_unique<Tree<T>>(val, nullptr, nullptr);
    else if (val <= tree->value) {
        tree->left = add(std::move(tree->left), val);
        return tree;
    }
    else {
        tree->right = add(std::move(tree->right), val);
        return tree;
    }
}

template<typename T>
tree_ptr<T> construct(std::vector<T> vals) {
    tree_ptr<T> result = nullptr;
    for (size_t i = 0; i < vals.size(); i++)
        result = add(std::move(result), vals[i]);
    return result;
}

int main() {
    std::vector<int> test = {3, 2, 5, 7, 1};
    auto result = construct(test);
    pte(result.get());
    std::cout << symmetric(result.get()) << std::endl;

    test = {5, 3, 18, 1, 4, 12, 21};
    std::cout << symmetric(construct(test).get()) << std::endl;

    test = {3, 2, 5, 7, 4};
    std::cout << symmetric(construct(test).get()) << std::endl;
}