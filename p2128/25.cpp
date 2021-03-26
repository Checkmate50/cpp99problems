#include<iostream>
#include<stdlib.h>
#include<time.h>

// Generate a random permutation of the elements of a list.
// Let's do this in-place with a pointer using the old shuffle algorithm
template<typename T>
void rnd_permu(T* v, int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        T temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
}

int main() {
    char test[11] = "abcdefghij";
    rnd_permu(test, 10);
    std::cout<<test<<std::endl;
}