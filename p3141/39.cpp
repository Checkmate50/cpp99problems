#include<iostream>
#include<math.h>
#include<vector>
#include"print.hpp"

// (*) A list of prime numbers.

bool is_prime(int num) {
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return false;
    return true;
}

std::vector<int> primesR(int low, int high) {
    std::vector<int> to_return;
    for (int i = low; i <= high; i++)
        if (is_prime(i))
            to_return.push_back(i);
    return to_return;
}

int main() {
    pve(primesR(10, 20));
}