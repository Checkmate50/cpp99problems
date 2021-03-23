#include<iostream>

// Insert an element at a given position into a list.

// Let's do this with pointers (even though it's trivial with vectors)
// Requires a pointer be allocated to be one larger than its current size (at least)
template<typename T>
void insertAt(T value, T* arr, int index, int size) {
    for (int i = size; i --> index;) {
        arr[i] = arr[i-1];
    }
    arr[index] = value;
}

int main() {
    char v[6] = "abcd";
    insertAt('X', v, 1, 5);
    std::cout << v << std::endl;
}