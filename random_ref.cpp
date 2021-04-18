#include<random>

int main() {
    int min = 5, max = 10;
    auto gen = std::mt19937(std::random_device()());
    auto dis = std::uniform_int_distribution<int>(min, max);
    auto val = dis(gen); // Random int in range [min, max].
}