#include<iostream>

//(*) Split a list into two parts; the length of the first part is given.

// So since this is trivial in C++, I'm instead going to do it for example strings with pointer / string magic
// Note that this is bad form, but is an interesting solution nonetheless

// Requires that `s` have initialized size at least one greater than size for this to work
// Kinda fun though
char** split(char* s, int size, int split_index) {
    for (int i = size; i > split_index; i--) {
        s[i] = s[i-1];
    }
    s[split_index] = '\0';
    char** to_return = new char*[2];
    to_return[0] = s;
    to_return[1] = s+split_index+1;
    return to_return;
}

int main() {
    char test[12] = "abcdefghik";
    auto result = split(test, 11, 3);
    std::cout << '[' << result[0] << ", " << result[1] << ']' << std::endl;
}