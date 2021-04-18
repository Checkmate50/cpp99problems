#include<iostream>
#include<utility>

//(**) Pack consecutive duplicates of list elements into sublists. 
// If a list contains repeated elements they should be placed in separate sublists.

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

int main() {
    char test[16] = "aaaabccaadeeee";
    auto result = pack(test);
    std::cout << '[';
    for (int i = 0; i < result.second.first - 1; i++) {
        for (int j = 0; j < result.second.second[i]; j++)
            std::cout << result.first[i][j];
        std::cout << ", ";
    }
    for (int i = 0; i < result.second.second[result.second.first - 1]; i++)
        std::cout << result.first[result.second.first -1][i];
    std::cout << ']' << std::endl;
}