#ifndef PRINT_H
#define PRINT_H

#include<iostream>
#include<vector>

void print_vec(std::vector<char> v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout<<v[i];
    }
}

template<typename T>
void print_vec(std::vector<T> v) {
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
void print_vec(std::vector<std::vector<T>> v) {
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

#endif