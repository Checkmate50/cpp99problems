#include "bst.hpp"
#include "print.hpp"
#include "bst_functions.hpp"

std::vector<tree_ptr<char>> cbal_tree(int nodes) {
    return cbal_tree(nodes, 'x');
}

int main() {
    pve(cbal_tree(23));
}