#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<string>
#include<variant>
#include<memory>
#include"print.hpp"

struct Node;

using combo = std::pair<char, double>;
using combo_ptr = std::unique_ptr<combo>;
using Node_ptr = std::unique_ptr<Node>;
using combo_node = std::variant<combo_ptr, Node_ptr>;
using encoding = std::pair<char, std::string>;

struct Node {
    combo_node left;
    combo_node right;
    double prob;
    Node(combo_node l, combo_node r, double prob) 
        : left(std::move(l)), right(std::move(r)), prob(prob) {}
};

// Sorts low to high
bool comp_weighted_encodings(const combo_node& l, const combo_node& r) {
    if (auto* lp = std::get_if<combo_ptr>(&l)) {
        if (auto* rp = std::get_if<combo_ptr>(&r))
            return (*lp)->second > (*rp)->second;
        return (*lp)->second > std::get<Node_ptr>(r)->prob;
    }
    auto& ln = std::get<Node_ptr>(l);
    if (auto* rp = std::get_if<combo_ptr>(&r)) {
        return ln->prob > (*rp)->second;
    }
    return ln->prob > std::get<Node_ptr>(r)->prob;
}

template<typename TIter>
std::priority_queue<combo_node, 
        std::vector<combo_node>, 
        decltype(&comp_weighted_encodings)> 
            sort_and_weight(const TIter start, int size) {
    std::vector<combo_ptr> vec;
    vec.reserve(size);
    double sum = 0;
    for (int i = 0; i < size; i++)
        sum += start[i].second;
    for (int i = 0; i < size; i++)
        vec.push_back(std::make_unique<combo>(start[i].first, start[i].second / sum));

    std::priority_queue<combo_node, 
        std::vector<combo_node>, 
        decltype(&comp_weighted_encodings)> result(comp_weighted_encodings);
    for (int i = 0; i < size; i++)
        result.push(std::move(vec[i]));
    return result;
}

combo_node build_node(combo_node&& l, combo_node&& r) {
    double probability;
    if (auto* lp = std::get_if<combo_ptr>(&l)) {
        if (auto* rp = std::get_if<combo_ptr>(&r)) {
            probability = (*lp)->second + (*rp)->second;
            return std::make_unique<Node>(std::move(*lp), std::move(*rp), probability);
        }
        auto& rn = std::get<Node_ptr>(r);
        probability = (*lp)->second + rn->prob;
        return std::make_unique<Node>(std::move(*lp), std::move(rn), probability);
    }
    auto& ln = std::get<Node_ptr>(l);
    if (auto* rp = std::get_if<combo_ptr>(&r)) {
        probability = ln->prob + (*rp)->second;
        return std::make_unique<Node>(std::move(ln), std::move(*rp), probability);
    }
    auto& rn = std::get<Node_ptr>(r);
    probability = ln->prob + rn->prob;
    return std::make_unique<Node>(std::move(ln), std::move(rn), probability);
}

template<typename T>
void move_all(std::vector<T>& v1, std::vector<T>&& v2) {
    v1.insert(v1.end(), std::move_iterator(v2.begin()), std::move_iterator(v2.end()));
}

std::vector<encoding> decodeTree(const Node_ptr& base, const std::string& symbols) {
    std::vector<encoding> result;
    if (std::holds_alternative<combo_ptr>(base->left)) {
        auto& lp = std::get<combo_ptr>(base->left);
        encoding l(lp->first, symbols + "0");
        result.push_back(l);
        if (std::holds_alternative<combo_ptr>(base->right)) {
            auto& rp = std::get<combo_ptr>(base->right);
            encoding r(rp->first, symbols + "1");
            result.push_back(r);
            return result;
        }
        auto right = decodeTree(std::get<Node_ptr>(base->right), symbols + "1");
        move_all(result, std::move(right));
        return result;
    }
    auto left = decodeTree(std::get<Node_ptr>(base->left), symbols + "0");
    move_all(result, std::move(left));
    if (std::holds_alternative<combo_ptr>(base->right)) {
        auto& rp = std::get<combo_ptr>(base->right);
        encoding r(rp->first, symbols + "1");
        result.push_back(r);
        return result;
    }
    auto right = decodeTree(std::get<Node_ptr>(base->right), symbols + "1");
    move_all(result, std::move(right));
    return result;
}

template<typename TIter>
std::vector<encoding> huffman(const TIter& start, const TIter& end) {
    int size = std::distance(start, end);
    if (size <= 0) {
        std::vector<encoding> result;
        return result;
    }
    auto weighted = sort_and_weight(start, size);
    while (weighted.size() > 1) {
        // Stupid oversight on priority_queue
        // https://stackoverflow.com/questions/20149471/move-out-element-of-std-priority-queue-in-c11
        auto next1 = std::move(const_cast<combo_node&>(weighted.top()));
        weighted.pop();
        auto next2 = std::move(const_cast<combo_node&>(weighted.top()));
        weighted.pop();
        weighted.push(build_node(std::move(next1), std::move(next2)));
    }
    auto top = std::move(const_cast<combo_node&>(weighted.top()));
    if (auto tnode = std::get_if<combo_ptr>(&top)) {
        std::vector<encoding> result;
        result.emplace_back((*tnode)->first, "0");
        return result;
    }
    return decodeTree(std::get<Node_ptr>(top), "");
}

int main() {
    std::pair<char, int> a('a', 45);
    std::pair<char, int> b('b', 13);
    std::pair<char, int> c('c', 12);
    std::pair<char, int> d('d', 16);
    std::pair<char, int> e('e', 9);
    std::pair<char, int> f('f', 5);
    std::vector<std::pair<char, int>> test = {a, b, c, d, e, f};
    pve(test);
    pve(huffman(test.begin(), test.end()));
}