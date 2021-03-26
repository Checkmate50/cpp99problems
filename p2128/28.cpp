#include<iostream>
#include"print.hpp"

//Sorting a list of lists according to length of sublists

// Let's just do a simple selection sort cause I'm lazy
template<typename T>
void lfsort(T start, T end) {
    auto length = std::distance(start, end);
    for (int i = 0; i < length; i++) {
        int minIndex = i;
        for (int j = i + 1; j < length; j++) {
            auto jStart = start[j];
            auto minStart = start[minIndex];
            if (std::distance(jStart.begin(), jStart.end()) < std::distance(minStart.begin(), minStart.end()))
                minIndex = j;
        }
        auto temp = start[i];
        start[i] = start[minIndex];
        start[minIndex] = temp;
    }
}

int main() {
    std::vector<std::string> test = {"abc","de","fgh","de","ijkl","mn","o"};
    lfsort(test.begin(), test.end());
    pve(test);
}