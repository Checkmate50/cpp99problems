#pragma once

#include<iostream>
#include<vector>
#include"bst.hpp"

void print_bool(bool b);

void print_vec(std::vector<char> v);

template<typename T>
void print_tree(const Tree<T>* t) {
    if (!t)
        std::cout << "Empty";
    else {
        std::cout << "(Branch " << t->value << ' ';
        print_tree((t->left).get());
        std::cout << ' ';
        print_tree((t->right).get());
        std::cout << ')';
    }
}

template<typename T>
void pte(const Tree<T>* t) {
    print_tree(t);
    std::cout << std::endl;
}

template<typename T>
void print_vec(const std::vector<tree_ptr<T>>& v) {
    std::cout<<'[';
    if (v.size() > 0) {
        for (int i = 0; i < v.size()-1; i++) {
            print_tree(v[i].get());
            std::cout << ',' << std::endl;
        }
        print_tree(v[v.size()-1].get());
    }
    std::cout<<']';
}

template<typename T, typename U>
void print_vec(const std::vector<std::pair<T, U>>& v) {
    std::cout<<'[';
    if (v.size() > 0) {
        for (int i = 0; i < v.size()-1; i++) {
            std::cout<<'('<<v[i].first<<','<<v[i].second<<')'<<", ";
        }
        std::cout<<'('<<v[v.size()-1].first<<','<<v[v.size()-1].second<<')';
    }
    std::cout<<']';
}

template<typename T>
void print_vec(const std::vector<T>& v) {
    std::cout<<'[';
    if (v.size() > 0) {
        for (int i = 0; i < v.size()-1; i++) {
            std::cout<<v[i]<<", ";
        }
        std::cout<<v[v.size()-1];
    }
    std::cout<<']';
}

template<typename T>
void print_vec(const std::vector<std::vector<T>>& v) {
    std::cout<<'[';
    if (v.size() >  0) {
        for (int i = 0; i < v.size()-1; i++) {
            print_vec(v[i]);
            std::cout<<", ";
        }
        if (v.size() > 0)
            print_vec(v[v.size()-1]);
    }
    std::cout<<']';
}

template<typename T>
void pve(T v) {
    print_vec(v);
    std::cout<<std::endl;
}