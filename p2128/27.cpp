#include<iostream>
#include<vector>
#include<cmath>
#include<numeric>
#include<algorithm>
#include"print.hpp"

// Create a vector containing all integers within a given range.
std::vector<int> range(size_t low, size_t high) {
    std::vector<int> result(high - low + 1);
    std::iota(result.begin(), result.end(), low);
    return result;
}

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

template<class TIter, typename T = typename TIter::value_type>
std::vector<T> removeFromContainer(TIter start, TIter end, std::vector<int> indices) {
    std::vector<T> result;
    for (int i = 0; i < std::distance(start, end); i++)
        if (std::find(indices.begin(), indices.end(), start[i]) == indices.end())
            result.push_back(start[i]);
    return result;
}

// Group the elements of a set into disjoint subsets.
// This takes two passes, so is a bit inefficient, but it works across containers and doesn't require unique items in the list
template<class TIter, typename T = typename TIter::value_type>
std::vector<std::vector<std::vector<T>>> group(std::vector<int> sizes, TIter start, TIter end) {
    std::vector<std::vector<std::vector<T>>> result;
    int dist = std::distance(start, end);
    int size_sum = 0;
    for (size_t i = 0; i < sizes.size(); i++) {
        size_sum += sizes[i];
    }
    if (size_sum != dist)
        return result;
    std::vector<std::vector<std::vector<int>>> combos;
    std::vector<int> indices = range(0, dist-1);
    std::vector<std::vector<int>> currentCombo;
    currentCombo.push_back(indices);
    combos.push_back(currentCombo);
    // First we find all the combos in terms of indices
    for (size_t i = 0; i < sizes.size(); i++) {
        std::vector<std::vector<std::vector<int>>> new_combos;
        for (size_t j = 0; j < combos.size(); j++) {
            std::vector<std::vector<int>> cur_combo;
            for (size_t k = 0; k < i; k++) {
                cur_combo.push_back(combos[j][k]);
            }
            auto cur_indices = combos[j][i]; // the next indices to test
            // Get the combations for the current appended indices
            auto combo = combinations(cur_indices.begin(), cur_indices.end(), sizes[i]);
            for (size_t k = 0; k < combo.size(); k++) {
                auto new_indices = removeFromContainer(cur_indices.begin(), cur_indices.end(), combo[k]);
                auto new_combo = cur_combo;
                new_combo.push_back(combo[k]);
                if (new_indices.size() > 0)
                    new_combo.push_back(new_indices);
                new_combos.push_back(new_combo);
            }
        }
        combos = std::move(new_combos);
    }
    // Finally, construct the results array from the calculated indices
    // Inefficient as noted above, but what _can_ you do
    for (size_t i = 0; i < combos.size(); i++) {
        std::vector<std::vector<T>> ires;
        for (size_t j = 0; j < combos[i].size(); j++) {
            std::vector<T> jres;
            for (size_t k = 0; k < combos[i][j].size(); k++) {
                jres.push_back(start[combos[i][j][k]]);
            }
            ires.push_back(jres);
        }
        result.push_back(ires);
    }
    return result;
}

int main() {
    std::vector<std::string> test = {"aldo","beat","carla","david","evi","flip","gary","hugo","ida"};
    std::vector<int> sizes = {2, 3, 4};
    auto result = group(sizes, test.begin(), test.end());
    pve(result);
}