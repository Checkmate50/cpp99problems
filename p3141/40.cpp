#include<iostream>
#include<math.h>

// (**) Goldbach's conjecture.

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

int main() {
    auto result = goldbach(28);
    std::cout<<'('<<result.first<<','<<result.second<<')'<<std::endl;
}