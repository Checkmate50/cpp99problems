#include "logic.hpp"

// (**) Define predicates and/2, or/2, nand/2, nor/2, xor/2, impl/2 and equ/2 (for logical equivalence) 
//  which succeed or fail according to the result of their respective operations; e.g. 
//  and(A,B) will succeed, if and only if both A and B succeed.

int main() {
    truth_table_n(3, [](std::vector<bool> v) { return v[0] iand (v[1] ior v[2]) iequ ((v[0] iand v[1]) ior v[0]) iand v[2]; });
}