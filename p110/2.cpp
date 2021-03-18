#include<iostream>

// (*) Find the last but one element of a list.

template<typename T, size_t N>
T myButLast(T (&v)[N]) {
    if (N <= 1)
        return 0;
    return v[N - 2];
}

int main() {
    int v[4] = {1, 2, 3, 4};
    std::cout << myButLast(v) << std::endl;
}