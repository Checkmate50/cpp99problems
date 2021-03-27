#include<iostream>
#include<math.h>
#include<vector>
#include"print.hpp"

// (**) Determine the prime factors of a given positive integer.

bool is_prime(int num) {
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return false;
    return true;
}

std::vector<int> prime_factors(int num) {
    std::vector<int> to_return;
    for (int i = 2; num > 1; i++) {
        if (is_prime(i) && num % i == 0) {
            num = num / i;
            to_return.push_back(i--);
        }
    }
    return to_return;
}

template<typename T>
std::vector<std::pair<T, int>> multiplicity(std::vector<T> v) {
    std::vector<std::pair<T, int>> to_return;
    for (int i = 0; i < v.size(); i++) {
        bool found = false;
        for (int j = 0; j < to_return.size(); j++) {
            if (v[i] == to_return[j].first) {
                to_return[j].second += 1;
                found = true;
                break;
            }
        }
        if (!found) {
            std::pair<T, int> new_pair(v[i], 1);
            to_return.push_back(new_pair);
        }
    }
    return to_return;
}

int main() {
    pve(multiplicity(prime_factors(315)));
}