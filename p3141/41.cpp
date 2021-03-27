#include<iostream>
#include<math.h>
#include<vector>
#include"print.hpp"
#include<algorithm>

// (**) Given a range of integers by its lower and upper limit, print a list of all even numbers and their Goldbach composition.

bool is_prime(int num) {
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return false;
    return true;
}

std::pair<int, int> goldbach(int num) {
    int i;
    for (i = 2; i < num; i++) {
        if (is_prime(i) && is_prime(num-i)) {
            std::pair<int, int> r(i, num-i);
            return r;
        }
    }
    std::pair<int, int> r(0, 0);
    return r;
}

std::vector<std::pair<int, int>> goldbach_list(int low, int high, int min) {
    if (low % 2 == 1)
        low++;
    std::vector<std::pair<int, int>> v;
    v.reserve((high - low) / 2);
    for (int i = low; i <= high; i += 2) {
        auto result = goldbach(i);
        if (std::min(result.first, result.second) >= min)
            v.push_back(result);
    }
    return v;
}

std::vector<std::pair<int, int>> goldbach_list(int low, int high) {
    return goldbach_list(low, high, 1);
}

int main() {
    pve(goldbach_list(2, 3000, 50));
}