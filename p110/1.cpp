#include<iostream>
#include<vector>

// (*) Find the last element of a list.

template<typename T>
T findLast(std::vector<T> v) {
    if (v.size() == 0)
        return 0;
    return v[v.size() - 1];
}

int main() {
    std::vector<int> v = {1, 2, 3, 4};
    std::cout << findLast(v) << std::endl;
}