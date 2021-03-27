#include<iostream>
#include<math.h>

// (**) Calculate Euler's totient function phi(m).

bool is_prime(int num) {
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return false;
    return true;
}

int totient(int num) {
    double prod = 1.0;
    for (int i = 2; i < num; i++)
        if (is_prime(i) && num % i == 0)
            prod *= 1.0 - (1.0 / i);
    return num * prod;
}

int main() {
    std::cout << totient(10) << std::endl;
}