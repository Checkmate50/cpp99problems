#include<iostream>
#include<utility>
#include<variant>
#include"sm.hpp"

// (*) Modified run-length encoding.
// Modify the result of problem 10 in such a way that if an element has no duplicates 
// it is simply copied into the result list. Only elements with duplicates are transferred as (N E) lists.

// This should obviously be done with vectors, I'm just using pointers for practice
template<typename T, size_t N>
std::pair<T**, std::pair<int, int*>> pack(T (&v)[N]) {
    int blocks = 1; // Start at one cause we have a starting block
    int max_size = 0;
    int cur_size = 1; // Since we start at 1
    // First figure out the dimensions of the storage list to initialize
    for (size_t i = 1; i < N; i++) {
        if (v[i] == v[i-1])
            cur_size++;
        else {
            blocks++;
            max_size = std::max(max_size, cur_size);
            cur_size = 0;
        }
    }
    max_size = std::max(max_size, cur_size);
    // Initialize the return thing to be as small as possible
    T** to_return = new T*[blocks];
    int index = 0;
    T* building = new T[max_size];
    int building_index = 0;
    int* list_sizes = new int[blocks];
    for (size_t i = 0; i < N; i++) {
        building[building_index] = v[i];
        if (i == N - 1 || v[i] == v[i+1])
            building_index++;
        else {
            to_return[index] = building;
            list_sizes[index] = building_index + 1;
            building = new T[max_size];
            index++;
            building_index = 0;
        }
    }
    std::pair<int, int*> sizes(index, list_sizes);
    std::pair<T**, std::pair<int, int*>> result(to_return, sizes);
    return result;
}

template<typename T, size_t N>
std::pair<std::variant<Single<T>*, Multiple<T>*>*, int> encode_modified(T (&v)[N]) {
    std::pair<T**, std::pair<int, int*>> result = pack(v);
    std::variant<Single<T>*, Multiple<T>*>* lst = \
        new std::variant<Single<T>*, Multiple<T>*>[result.second.first];
    for (int i = 0; i < result.second.first; i++) {
        if (result.second.second[i] == 1) {
            Single<T>* s = new Single<T>(*(result.first[i]));
            lst[i] = s;
        }
        else {
            Multiple<T>* m = new Multiple<T>(result.second.second[i], *(result.first[i]));
            lst[i] = m;
        }
    }
    std::pair<std::variant<Single<T>*, Multiple<T>*>*, int> to_return(lst, result.second.first);
    return to_return;
}

int main() {
    char test[15] = "aaaabccaadeeee";
    auto result = encode_modified(test);
    std::cout << '[';
    std::variant<Single<char>*, Multiple<char>*> temp;
    for (int i = 0; i < result.second - 1; i++) {
        temp = result.first[i];
        print_variant(temp, print_single<char>, print_multiple<char>);
        std::cout << ", ";
    }
    temp = result.first[result.second - 1];
    print_variant(temp, print_single<char>, print_multiple<char>);
    std::cout << ']' << std::endl;
}