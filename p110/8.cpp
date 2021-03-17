#include<iostream>
#include<vector>
#include<variant>

int main() {
    // This type _looks_ insane, but it's what I could figure out
    std::variant<int, float> x = 5;
    int y = std::get<int>(x);
    std::cout << y << std::endl;
}