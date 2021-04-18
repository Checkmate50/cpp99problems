#include "print.hpp"

void print_bool(bool b) {
    std::cout << (b ? "True" : "False");
}

void print_vec(std::vector<char> v) {
    for (size_t i = 0; i < v.size(); i++) {
        std::cout<<v[i];
    }
}