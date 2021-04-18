#include<iostream>
#include<vector>
#include<cmath>
#include"print.hpp"

uint_fast32_t choose(int N, int K) {
    auto nf = (uint_fast32_t)std::tgamma(N+1);
    auto kf = (uint_fast32_t)std::tgamma(K+1);
    auto nkf = (uint_fast32_t)std::tgamma(N-K+1);
    return nf / (kf * nkf);
}

// (**) Generate the combinations of K distinct objects chosen from the N elements of a list
template<class TIter, typename T = typename TIter::value_type>
std::vector<std::vector<T>> combinations(TIter start, TIter end, int count) {
    std::vector<std::vector<T>> result;
    int dist = std::distance(start, end);
    if (count > dist)
        return result;
    auto size = choose(dist, count);
    result.reserve(size);
    std::vector<TIter> iterator_list;
    TIter start_iter = start;
    for (; count --> 0; ) {
        TIter new_iter = start_iter;
        iterator_list.push_back(new_iter);
        start_iter++;
    }
    bool finished = false;
    while (!finished) {
        std::vector<T> next_item;
        for (size_t i = 0; i < iterator_list.size(); i++)
            next_item.push_back(*iterator_list[i]);
        for (size_t i = iterator_list.size(); i --> 0; ) {
            iterator_list[i]++;
            if (iterator_list[i]+iterator_list.size()-i-1 >= end) {
                if (i == 0) {
                    finished = true;
                    break;
                }
            }
            else {
                for (size_t j = i+1; j < iterator_list.size(); j++) {
                    if (j == 0)
                        iterator_list[j]++;
                    else
                        iterator_list[j] = iterator_list[j-1]+1;
                }
                break;
            }
        }
        result.push_back(next_item);
    }
    return result;
}

int main() {
    std::string c = "abcdefghij";
    auto result = combinations(c.begin(), c.end(), 3);
    pve(result);
}