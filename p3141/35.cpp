#include<iostream>
#include<math.h>
#include<vector>
#include"print.hpp"

// (**) Determine the prime factors of a given positive integer. Construct a flat list containing the prime factors in ascending order.

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

int main() {
    pve(prime_factors(315));
}