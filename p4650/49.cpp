#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
#include"print.hpp"

std::vector<std::string> gray_codes(int n) {
    std::vector<std::string> result;
    if (n > 63)
        return result;
    unsigned long long size = (unsigned long long int)pow(2.0, n);
    result.reserve(size);
    for (unsigned long long int i = 0; i < size; i++) {
        int copy = i;
        std::string s;
        s.reserve(n);
        for (int j = 0; j < n; j++) {
            // Magic bit-fiddling
            // Just stare at the solution long enough, and you'll see it :)
            int bit = (copy & 1) ^ ((copy & 2) >> 1);
            s.push_back(bit ? '1' : '0');
            copy >>= 1;
        }
        // This can be done better, but I'm lazy af
        std::reverse(s.begin(), s.end());
        result.push_back(s);
    }
    return result;
}

int main() {
    pve(gray_codes(3));
}