#include "bst.hpp"
#include "print.hpp"
#include "bst_functions.hpp"
#include<iostream>

// Let us call a binary tree symmetric if you can draw a vertical line through the root node and then 
// the right subtree is the mirror image of the left subtree. Write a predicate symmetric/1 to check 
// whether a given binary tree is symmetric. Hint: Write a predicate mirror/2 first to check whether 
// one tree is the mirror image of another. We are only interested in the structure, not in the contents of the nodes.

int main() {
    auto basic = std::make_unique<Tree<int>>(1, nullptr, nullptr);
    std::cout << symmetric(basic.get()) << std::endl;

    auto leaf = std::make_unique<Tree<int>>(2, nullptr, nullptr);
    auto t = std::make_unique<Tree<int>>(3, std::move(basic), std::move(leaf));
    std::cout << symmetric(t.get()) << std::endl;

    leaf = std::make_unique<Tree<int>>(2, nullptr, nullptr);
    auto q = std::make_unique<Tree<int>>(3, std::move(t), std::move(leaf));
    std::cout << symmetric(q.get()) << std::endl;

    basic = std::make_unique<Tree<int>>(1, nullptr, nullptr);
    leaf = std::make_unique<Tree<int>>(2, nullptr, nullptr);
    t = std::make_unique<Tree<int>>(3, std::move(basic), nullptr);
    q = std::make_unique<Tree<int>>(3, nullptr, std::move(leaf));
    auto test = std::make_unique<Tree<int>>(5, std::move(t), std::move(q));
    std::cout << symmetric(test.get()) << std::endl;
}