#include<iostream>

// (*) Find the K'th element of a list. The first element in the list is number 1.

template<typename T>
T elementAt(T v[], int size, int index) {
    if (index > size)
        return 0;
    return v[index - 1];
}

int main() {
    int v[4] = {1, 2, 3, 4};
    std::cout << elementAt(v, 4, 2) << std::endl;
}