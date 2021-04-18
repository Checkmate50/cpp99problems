#include<iostream>

// (**) Replicate the elements of a list a given number of times.

template<typename T, size_t N>
std::pair<T*, int> repli(T (&v)[N], int count) {
    T* result = new T[count * N];
    for (size_t i = 0; i < N; i++)
        for (int j = 0; j < count; j++)
            result[count*i + j] = v[i];
    std::pair<T*, int> to_return(result, count * N);
    return to_return;
}

int main() {
    int test[3] = { 1, 2, 3 };
    auto result = repli(test, 3);
    std::cout << '[';
    for (int i = 0; i < result.second - 1; i++) {
        std::cout << result.first[i] << ", ";
    }
    std::cout << result.first[result.second - 1] << ']' << std::endl;
}