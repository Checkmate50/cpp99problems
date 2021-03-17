#include<iostream>

// (*) Reverse a list.

template<typename T>
void myReverse(T v[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int j = size - i - 1;
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
}

int main() {
    int v[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        std::cout << v[i] << std::endl;
    std::cout << "---" << std::endl;
    myReverse(v, 5);
    for (int i = 0; i < 5; i++)
        std::cout << v[i] << std::endl;
}