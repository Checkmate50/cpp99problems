#include<iostream>
#include<utility>
#include<variant>
#include<vector>
#include"sm.hpp"

// (**) Run-length encoding of a list (direct solution).

// Implement the so-called run-length encoding data compression method directly. 
// I.e. don't explicitly create the sublists containing the duplicates, as in problem 9, but only count them. 
// As in problem P11, simplify the result list by replacing the singleton lists (1 X) by X.

template<typename T>
std::vector<std::variant<Single<T>*, Multiple<T>*>> encode_direct(std::vector<T> v) {
    std::vector<std::variant<Single<T>*, Multiple<T>*>> to_return;
    if (v.size() == 0)
        return to_return;
    T next_val = v[0];
    int next_size = 1;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == v[i-1])
            next_size++;
        else {
            if (next_size == 1) {
                Single<T>* s = new Single(next_val);
                to_return.push_back(s);
            }
            else {
                Multiple<T>* m = new Multiple(next_size, next_val);
                to_return.push_back(m);
            }
            next_val = v[i];
            next_size = 1;
        }
    }
    if (next_size == 1) {
        Single<T>* s = new Single(next_val);
        to_return.push_back(s);
    }
    else {
        Multiple<T>* m = new Multiple(next_size, next_val);
        to_return.push_back(m);
    }
    return to_return;
}

int main() {
    char init[15] = "aaaabccaadeeee";
    std::vector<char> test;
    for (int i = 0; i < 14; i++)
        test.push_back(init[i]);
    auto result = encode_direct(test);
    std::cout << '[';
    std::variant<Single<char>*, Multiple<char>*> temp;
    for (int i = 0; i < result.size() - 1; i++) {
        temp = result[i];
        print_variant(temp, print_single<char>, print_multiple<char>);
        std::cout << ", ";
    }
    temp = result[result.size() - 1];
    print_variant(temp, print_single<char>, print_multiple<char>);
    std::cout << ']' << std::endl;
}