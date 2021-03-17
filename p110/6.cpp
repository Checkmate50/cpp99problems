#include<iostream>

// (*) Find out whether a list is a palindrome. A palindrome can be read forward or backward; e.g. (x a m a x).

template<typename T>
bool isPalindrome(T v[], int size) {
    for (int i = 0; i < size / 2; i++)
        if (v[i] != v[size - i - 1])
            return false;
    return true;
}

int main() {
    int v[5] = {1, 2, 3, 2, 1};
    std::cout << isPalindrome(v, 5) << std::endl; // Should be 1
    int u[5] = {1, 3, 3, 2, 1};
    std::cout << isPalindrome(u, 5) << std::endl; // Should be 0
    char t[7] = "abccba";
    std::cout << isPalindrome(t, 6) << std::endl; // Should be 1, note the size change
}