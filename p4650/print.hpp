#pragma once

#include<iostream>
#include<vector>

void print_bool(bool b);

void print_vec(std::vector<char> v);

template<typename T, typename U>
void print_vec(std::vector<std::pair<T, U>> v) {
    std::cout<<'[';
    if (v.size() > 0) {
        for (size_t i = 0; i < v.size()-1; i++) {
            std::cout<<'('<<v[i].first<<','<<v[i].second<<')'<<", ";
        }
        std::cout<<'('<<v[v.size()-1].first<<','<<v[v.size()-1].second<<')';
    }
    std::cout<<']';
}

template<typename T>
void print_vec(std::vector<T> v) {
    std::cout<<'[';
    if (v.size() > 0) {
        for (size_t i = 0; i < v.size()-1; i++) {
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
        for (size_t i = 0; i < v.size()-1; i++) {
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