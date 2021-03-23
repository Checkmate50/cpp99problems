#include<iostream>

// (**) Drop every N'th element from a list.
// Doing this in-place for fun and profit

// Returns the final "length"
template<typename T, size_t S>
int drop(T (&v)[S], int N) {
    int count = 0;
    int shift = 0;
    for (int i = 1; i < S; i++) {
        count++;
        if (count % (N - 1) == 0) {
            count = 0;
            shift++;
        }
        v[i] = v[i + shift];
    }
    if (shift > 0)
        return S - shift + 1;
    return S;
}

int main() {
    char test[11] = "abcdefghij";
    int size = drop(test, 3);
    for (int i = 0; i < size; i++) {
        std::cout << test[i];
    }
    std::cout << std::endl;
}