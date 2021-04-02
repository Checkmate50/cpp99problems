#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<string>
#include<variant>
#include"print.hpp"

typedef std::pair<char, double> combo;
#define combo_node std::variant<const combo*, const Node*>
typedef std::pair<char, std::string> encoding;

struct Node {
    combo_node left;
    combo_node right;
    double prob;
    Node(const combo* l, const combo* r, const double& prob) 
        : left(l), right(r), prob(prob) {}
    Node(const Node* l, const combo* r, double prob) 
        : left(l), right(r), prob(prob) {}
    Node(const combo* l, const Node* r, double prob) 
        : left(l), right(r), prob(prob) {}
    Node(const Node* l, const Node* r, double prob) 
        : left(l), right(r), prob(prob) {}
};

// Sorts low to high
bool comp_weighted_encodings(const combo_node& l, 
        const combo_node& r) {
    if (std::holds_alternative<const combo*>(l)) {
        auto lp = std::get<const combo*>(l);
        if (std::holds_alternative<const combo*>(r)) {
            auto rp = std::get<const combo*>(r);
            return lp->second > rp->second;
        }
        return lp->second > std::get<const Node*>(r)->prob;
    }
    auto ln = std::get<const Node*>(l);
    if (std::holds_alternative<const combo*>(r)) {
        auto rp = std::get<const combo*>(r);
        return ln->prob > rp->second;
    }
    return ln->prob > std::get<const Node*>(r)->prob;
}

template<typename TIter>
std::priority_queue<combo_node, 
        std::vector<combo_node>, 
        decltype(&comp_weighted_encodings)> 
            sort_and_weight(const TIter start, const int& size) {
    std::vector<const combo*> vec;
    vec.reserve(size);
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += start[i].second;
    }
    for (int i = 0; i < size; i++) {
        const combo* pf = new combo(start[i].first, start[i].second / sum);
        vec.push_back(pf);
    }
    std::priority_queue<combo_node, 
        std::vector<combo_node>, 
        decltype(&comp_weighted_encodings)> result(vec.begin(), vec.end(), 
            comp_weighted_encodings);
    return result;
}

std::vector<encoding> decodeTree(const Node* base, const std::string& symbols);

Node* build_node(const combo_node& l, 
        const combo_node& r) {
    double probability;
    if (auto lp = std::get_if<const combo*>(&l)) {
        if (auto rp = std::get_if<const combo*>(&r)) {
            probability = (*lp)->second + (*rp)->second;
            return new Node(*lp, *rp, probability);
        }
        auto& rn = std::get<const Node*>(r);
        probability = (*lp)->second + rn->prob;
        return new Node(*lp, rn, probability);
    }
    auto& ln = std::get<const Node*>(l);
    if (auto rp = std::get_if<const combo*>(&r)) {
        probability = ln->prob + (*rp)->second;
        return new Node(ln, *rp, probability);
    }
    auto& rn = std::get<const Node*>(r);
    probability = ln->prob + rn->prob;
    return new Node(ln, rn, probability);
}

template<typename T>
void push_all(std::vector<T>& v1, const std::vector<T>& v2) {
    v1.insert(v1.end(), v2.begin(), v2.end());
}

std::vector<encoding> decodeTree(const Node* base, const std::string& symbols) {
    std::vector<encoding> result;
    if (std::holds_alternative<const combo*>(base->left)) {
        auto lp = std::get<const combo*>(base->left);
        encoding l(lp->first, symbols + "0");
        result.push_back(l);
        if (std::holds_alternative<const combo*>(base->right)) {
            auto rp = std::get<const combo*>(base->right);
            encoding r(rp->first, symbols + "1");
            result.push_back(r);
            return result;
        }
        auto right = decodeTree(std::get<const Node*>(base->right), symbols + "1");
        push_all(result, right);
        return result;
    }
    auto left = decodeTree(std::get<const Node*>(base->left), symbols + "0");
    push_all(result, left);
    if (std::holds_alternative<const combo*>(base->right)) {
        auto rp = std::get<const combo*>(base->right);
        encoding r(rp->first, symbols + "1");
        result.push_back(r);
        return result;
    }
    auto right = decodeTree(std::get<const Node*>(base->right), symbols + "1");
    push_all(result, right);
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
        auto next1 = weighted.top();
        weighted.pop();
        auto next2 = weighted.top();
        weighted.pop();
        weighted.push(build_node(next1, next2));
    }
    auto top = weighted.top();
    if (auto tnode = std::get_if<const combo*>(&top)) {
        std::vector<encoding> result;
        encoding p((*tnode)->first, "0");
        result.push_back(p);
        return result;
    }
    return decodeTree(std::get<const Node*>(top), "");
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