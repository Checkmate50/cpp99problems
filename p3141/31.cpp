#include<iostream>
#include<math.h>

//(**) Determine whether a given integer number is prime.

bool is_prime(int num) {
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return false;
    return true;
}

int main() {
    std::cout << is_prime(7) << std::endl;
    std::cout << is_prime(49) << std::endl;
    std::cout << is_prime(53) << std::endl;
}