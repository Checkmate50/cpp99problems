#include<iostream>

// (**) Rotate a list N places to the left.

template<typename T, size_t N>
void rotate(T (&v)[N], int amount) {
    amount = amount % (int)N;
    if (amount == 0)
        return;
    int absamount = std::abs(amount);
    T* temp = new T[absamount];
    // Let's do this in two passes for readability
    // Well, more like one + amount passes
    for (int i = 0; i < absamount; i++) {
        if (amount > 0)
            temp[i] = v[i];
        else // amount < 0
            temp[i] = v[N - absamount + i - 1];
    }
    if (amount > 0) {
        for (int i = 0; i < N; i++) {
            if (i >= (N - amount))
                v[i] = temp[i-N+amount];
            else
                v[i] = v[i+amount];
        }
    }
    else { // amount < 0
        for (int i = N - 1; i --> 0;) //heh
            if (i < absamount) 
                v[i] = temp[i];
            else
                v[i] = v[i+amount];
    }
}

int main() {
    char v[11] = "abcdefghij";
    rotate(v, -9);
    for (int i = 0; i < 11; i++) {
        std::cout << v[i];
    }
    std::cout << std::endl;
}