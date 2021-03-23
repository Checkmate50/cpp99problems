#include<iostream>

// (*) Remove the K'th element from a list.

template<typename T, size_t N>
void removeAt(T (&v)[N], int index) {
    for (int i = index; i < N - 1; i++) {
        v[i] = v[i+1];
    }
}

int main() {
    char v[11] = "abcdefghij";
    removeAt(v, 3);
    std::cout<<v<<std::endl;
}