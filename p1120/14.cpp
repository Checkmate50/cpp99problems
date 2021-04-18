#include<iostream>

//(*) Duplicate the elements of a list.

template<typename T, size_t N>
std::pair<T*, int> dupli(T (&v)[N]) {
    T* result = new T[2 * N];
    for (int i = 0; i < N; i++) {
        result[2*i] = v[i];
        result[2*i + 1] = v[i];
    }
    std::pair<T*, int> to_return(result, 2 * N);
    return to_return;
}

int main() {
    int test[3] = { 1, 2, 3 };
    auto result = dupli(test);
    std::cout << '[';
    for (size_t i = 0; i < result.second - 1; i++) {
        std::cout << result.first[i] << ", ";
    }
    std::cout << result.first[result.second - 1] << ']' << std::endl;
}