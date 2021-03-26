#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<numeric>

// Create a vector containing all integers within a given range.
std::vector<int> range(size_t low, size_t high) {
    std::vector<int> result(high - low + 1);
    std::iota(result.begin(), result.end(), low);
    return result;
}

// Extract a given number of randomly selected elements from a vector.
// Avoid modifying the underlying vector with a copy
// Assumes a seed has already been set for rand
template<typename T>
T rnd_select(T const& v, int count) {
    T cp = v;
    T result;
    result.reserve(count);
    if (count >= cp.size())
        return cp;
    for (int i = 0; i < count; i++) {
        int index = rand() % cp.size();
        result.push_back(cp[index]);
        cp.erase(cp.begin()+index);
    }
    return result;
}

std::vector<int> diff_select(int count, int high) {
    return rnd_select(range(0, high), count);
}

int main() {
    auto result = diff_select(6, 49);
    std::cout << '[';
    for (int i = 0; i < result.size()-1; i++)
        std::cout << result[i] << ',';
    std::cout << result[result.size()-1] << ']' << std::endl;
}