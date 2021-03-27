#include<iostream>
#include<algorithm>

// (*) Determine whether two positive integer numbers are coprime. Two numbers are coprime if their greatest common divisor equals 1.

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

bool coprime(int a, int b) {
    return gcd(a, b) > 1;
}

int main() {
    std::cout << coprime(36, 63) << " " << coprime(15, 64) << std::endl;
}