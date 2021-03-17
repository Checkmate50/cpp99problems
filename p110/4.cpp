#include<iostream>
#include<vector>

// (*) Find the number of elements of a list.

template<typename T>
int myLength(std::vector<T> v) {
    return v.size();
}

int main() {
    std::vector<int> v = {1, 2, 3, 4};
    std::cout << myLength(v) << std::endl;
}