#include<iostream>
#include<math.h>
#include<vector>
#include"print.hpp"
#include <chrono>

// (**) Calculate Euler's totient function phi(m) (improved).

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
    for (size_t i = 0; i < v.size(); i++) {
        bool found = false;
        for (size_t j = 0; j < to_return.size(); j++) {
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

int totient1(int num) {
    double prod = 1.0;
    for (int i = 2; i < num; i++)
        if (is_prime(i) && num % i == 0)
            prod *= 1.0 - (1.0 / i);
    return num * prod;
}

int totient2(int num) {
    auto factors = multiplicity(prime_factors(num));
    double result = 1;
    for (size_t i = 0; i < factors.size(); i++)
        result *= (factors[i].first - 1) * pow(factors[i].first, factors[i].second - 1);
    return result; 
}

int main() {
    auto before  = std::chrono::duration_cast< std::chrono::milliseconds >(
        std::chrono::system_clock::now().time_since_epoch()).count();
    for (int i = 0; i < 1000; i++)
        totient1(10800 + i);
    auto after = std::chrono::duration_cast< std::chrono::milliseconds >(
        std::chrono::system_clock::now().time_since_epoch()).count();
    std::cout << after - before << std::endl;
    before = std::chrono::duration_cast< std::chrono::milliseconds >(
        std::chrono::system_clock::now().time_since_epoch()).count();
    for (int i = 0; i < 1000; i++)
        totient2(10800 + i);
    after = std::chrono::duration_cast< std::chrono::milliseconds >(
        std::chrono::system_clock::now().time_since_epoch()).count();
    std::cout << after - before << std::endl;
}