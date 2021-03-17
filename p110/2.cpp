#include<iostream>

// (*) Find the last but one element of a list.

template<typename T>
T myButLast(T v[], int size) {
    if (size <= 1)
        return 0;
    return v[size - 2];
}

int main() {
    int v[4] = {1, 2, 3, 4};
    std::cout << myButLast(v, 4) << std::endl;
}