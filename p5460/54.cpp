#include "bst.hpp"
#include "print.hpp"

// Check whether a given term represents a binary tree
// Handled by the type system
// See bst.hpp and print.hpp for the relevant definitions

int main() {
    tree_ptr<nullptr_t> empty = nullptr;
    pte(empty.get());

    auto basic = std::make_unique<Tree<int>>(1, nullptr, nullptr);
    pte(basic.get());

    auto leaf = std::make_unique<Tree<int>>(2, nullptr, nullptr);
    auto t = std::make_unique<Tree<int>>(3, std::move(basic), std::move(leaf));
    pte(t.get());
}