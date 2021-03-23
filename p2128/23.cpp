#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<memory>

// Extract a given number of randomly selected elements from a vector.
// Avoid modifying the underlying vector with a copy
// Assumes a seed has already been set for rand
template<typename T>
std::vector<T> rnd_select(std::vector<T> v, int count) {
    std::vector<T> cp = v;
    std::vector<T> result;
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

int main() {
    std::string s = "abcdefgh";
    std::vector<char> test;
    srand(time(NULL));
    for (int i = 0; i < s.length(); i++)
        test.push_back(s[i]);
    auto result = rnd_select(test, 3);
    for (int i = 0; i < result.size(); i++)
        std::cout<<result[i];
    std::cout<<std::endl;
}