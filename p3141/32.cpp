#include<iostream>
#include<algorithm>

// (**) Determine the greatest common divisor of two positive integer numbers. Use Euclid's algorithm.

int gcd(int a, int b) {
    int larger = std::max(a, b);
    int smaller = std::min(a, b);
    int temp;
    while (larger % smaller != 0) {
        temp = larger % smaller;
        larger = smaller;
        smaller = temp;
    }
    return std::abs(smaller);
}

int main() {
    std::cout << gcd(36, 63) << " " << gcd(1071, 462) << std::endl;
}