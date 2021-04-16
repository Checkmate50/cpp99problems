#pragma once

#include <memory>

template<typename T>
struct Tree;

template<typename T>
using tree_ptr = std::unique_ptr<Tree<T>>;

template<typename T>
struct Tree {
    T value;
    tree_ptr<T> left;
    tree_ptr<T> right;
    Tree(T value, tree_ptr<T>&& left, tree_ptr<T>&& right) : 
        value(value), left(std::move(left)), right(std::move(right)) {}
};