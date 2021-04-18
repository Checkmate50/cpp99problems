#include<iostream>
#include<vector>
#include<variant>

// (**) Flatten a nested list structure.

template<typename T>
std::vector<T> flatten(std::vector<T> v) {
    return v;
}

template<typename T, typename U>
using vtype = std::vector<std::variant<std::vector<T>, U>>;
template<typename T, typename U>
std::vector<U> flatten(const vtype<T, U>& v) {
    std::vector<U> to_return = {};
    for (auto& iter : v) {
        if (auto* element = std::get_if<U>(&iter)) {
            to_return.push_back(*element);
        }
        else {
            auto subresults = flatten(std::get<std::vector<T>>(iter));
            to_return.insert(to_return.end(),std::move_iterator(subresults.begin()),std::move_iterator(subresults.end()));
        }
    }
    return to_return;
}

int main() {
    // This type _looks_ insane, but it's what I could figure out
    std::vector<std::variant<std::vector<std::variant<std::vector<int>, int>>, int>> v = {};
    v.push_back(5);
    std::vector<std::variant<std::vector<int>, int>> temp = {2, 7};
    v.push_back(temp);
    std::vector<std::variant<std::vector<int>, int>> temp2 = { 9 };
    std::vector<int> temp3 = {3, 1};
    temp2.push_back(temp3);
    temp2.push_back(4);
    v.push_back(temp2);
    v.push_back(6);
    std::vector<int> result = flatten(v);
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}