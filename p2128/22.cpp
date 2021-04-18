#include<iostream>
#include<vector>
#include<memory>
#include <numeric>

// Create a vector containing all integers within a given range.
std::vector<int> range(size_t low, size_t high) {
    std::vector<int> result(high - low + 1);
    std::iota(result.begin(), result.end(), low);
    return result;
}

int main() {
    auto test = range(4, 9);
    std::cout<<'[';
    for (size_t i = 0; i < test.size()-1; i++)
        std::cout<<test[i]<<',';
    std::cout<<test[test.size()-1]<<']'<<std::endl;
}