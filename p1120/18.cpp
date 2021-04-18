#include<iostream>
#include<vector>

// (**) Extract a slice from a list.

template<typename T>
std::vector<T> slice(std::vector<T> arr, int low, int high) {
    std::vector<T> result;
    for (int i = low; i < high; i++) {
        result.push_back(arr[i]);
    }
    return result;
}

int main() {
    std::string s = "abcdefghij";
    std::vector<char> test;
    for (size_t i = 0; i < s.length(); i++) {
        test.push_back(s[i]);
    }
    auto result = slice(test, 3, 7);
    for (size_t i = 0; i < result.size(); i++)
        std::cout << result[i];
    std::cout << std::endl;
}