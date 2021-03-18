#include <iostream>
#include <vector>

// (*) Run-length encoding of a list. Use the result of problem P09 to implement the so-called run-length encoding 
// data compression method. Consecutive duplicates of elements are encoded as lists (N E)
//  where N is the number of duplicates of the element E.

template<typename T, size_t N>
std::pair<T**, std::pair<int, int*>> pack(T (&v)[N]) {
    int blocks = 1; // Start at one cause we have a starting block
    int max_size = 0;
    int cur_size = 1; // Since we start at 1
    // First figure out the dimensions of the storage list to initialize
    for (int i = 1; i < N; i++) {
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
    for (int i = 0; i < N; i++) {
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
std::pair<std::pair<int, T>*, int> encode(T (&v)[N]) {
    auto pack_result = pack(v);
    auto pack_sizes = pack_result.second;
    std::pair<int, T>* pair_list = new std::pair<int, T>[pack_sizes.first];
    for (int i = 0; i < pack_sizes.first; i++) {
        std::pair<int, T> p(pack_sizes.second[i], pack_result.first[i][0]);
        pair_list[i] = p;
    }
    std::pair<std::pair<int, T>*, int> result(pair_list, pack_sizes.first);
    return result;
}

int main() {
    char test[16] = "aaaabccaadeeee";
    auto result = encode(test);
    std::cout << '[';
    std::pair<int, char> temp;
    for (int i = 0; i < result.second - 1; i++) {
        temp = result.first[i];
        std::cout << "(" << temp.first << ", " << temp.second << ")";
        std::cout << ", ";
    }
    temp = result.first[result.second - 1];
    std::cout << "(" << temp.first << ", " << temp.second << ")";
    std::cout << ']' << std::endl;
}