#include<iostream>

// (**) Eliminate consecutive duplicates of list elements.

template<typename T>
void compress(T* compress, int size) {
    int found = 0;
    for (int i = 1; i < size - found; i++) {
        if (compress[i] == compress[i - 1]) {
            for (int j = i; j < size - found; j++)
                compress[j] = compress[j + 1];
            found++;
            i--;
        }
    }
}

int main() {
    char word[20] = "aaaabccaadeeee";
    std::cout << word << std::endl;
    compress(word, 20);
    std::cout << word << std::endl;
}