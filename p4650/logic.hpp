#pragma once

#include<iostream>
#include<vector>
#include<math.h>
#include"print.hpp"
#include<string>

bool myand(bool l, bool r);

bool myor(bool l, bool r);

bool mynand(bool l, bool r);

bool mynor(bool l, bool r);

bool myxor(bool l, bool r);

bool myimpl(bool l, bool r);

bool myequ(bool l, bool r);

// A struct for building the infix operations
// See https://stackoverflow.com/questions/15632217/defining-new-infix-operators for reasoning
struct logic_infix_struct {
    char op;
    bool lhs;
    bool rhs;
    void set_op(char op)    { this->op  = op;  }
    void set_lhs(bool lhs)  { this->lhs = lhs; }
    void set_rhs(bool rhs)  { this->rhs = rhs; }
    virtual explicit operator bool() const = 0;
};

struct and_infix_struct : public logic_infix_struct {
    explicit operator bool() const {
        return myand(lhs, rhs);
    }
};

struct or_infix_struct : public logic_infix_struct {
    explicit operator bool() const {
        return myor(lhs, rhs);
    }
};

struct nand_infix_struct : public logic_infix_struct {
    explicit operator bool() const {
        return mynand(lhs, rhs);
    }
};

struct nor_infix_struct : public logic_infix_struct {
    explicit operator bool() const {
        return mynor(lhs, rhs);
    }
};

struct xor_infix_struct : public logic_infix_struct {
    explicit operator bool() const {
        return myxor(lhs, rhs);
    }
};

struct impl_infix_struct : public logic_infix_struct {
    explicit operator bool() const {
        return myimpl(lhs, rhs);
    }
};

struct equ_infix_struct : public logic_infix_struct {
    explicit operator bool() const {
        return myequ(lhs, rhs);
    }
};

inline and_infix_struct     and_infix_object;
inline or_infix_struct      or_infix_object;
inline nand_infix_struct    nand_infix_object;
inline nor_infix_struct     nor_infix_object;
inline xor_infix_struct     xor_infix_object;
inline impl_infix_struct    impl_infix_object;
inline equ_infix_struct     equ_infix_object;

// lots of operators defined here
and_infix_struct& operator&(const bool& lhs, const logic_infix_struct& rhs);
bool operator&(const logic_infix_struct& lhs, const bool& rhs);
or_infix_struct& operator|(const bool& lhs, const logic_infix_struct& rhs);
bool operator|(const logic_infix_struct& lhs, const bool& rhs);
nand_infix_struct& operator+(const bool& lhs, const logic_infix_struct& rhs);
bool operator+(const logic_infix_struct& lhs, const bool& rhs);
nor_infix_struct& operator-(const bool& lhs, const logic_infix_struct& rhs);
bool operator-(const logic_infix_struct& lhs, const bool& rhs);
xor_infix_struct& operator^(const bool& lhs, const logic_infix_struct& rhs);
bool operator^(const logic_infix_struct& lhs, const bool& rhs);
impl_infix_struct& operator*(const bool& lhs, const logic_infix_struct& rhs);
bool operator*(const logic_infix_struct& lhs, const bool& rhs);
equ_infix_struct& operator/(const bool& lhs, const logic_infix_struct& rhs);
bool operator/(const logic_infix_struct& lhs, const bool& rhs);

// Here's where the actual macro magic happens
#define iand   &and_infix_object&
#define ior    |or_infix_object|
#define inand  +nand_infix_object+
#define inor   -nor_infix_object-
#define ixor   ^xor_infix_object^
#define iimpl  *impl_infix_object*
#define iequ   /equ_infix_object/

template<typename F>
void print_truth_line(bool l, bool r, F tf) {
    print_bool(l);
    std::cout << '\t';
    print_bool(r);
    std::cout << '\t';
    print_bool(tf(l, r));
    std::cout << std::endl;
}

template<typename F>
void print_truth_line(std::vector<bool> v, F tf) {
    for (size_t i = 0; i < v.size(); i++) {
        print_bool(v[i]);
        std::cout << '\t';
    }
    print_bool(tf(v));
    std::cout << std::endl;
}

template<typename F>
void truth_table(F truth_function) {
    static_assert(std::is_invocable_r_v<bool, F, bool, bool>, "Invalid argument to truth table, expected binary boolean function");
    print_truth_line(true,  true,   truth_function);
    print_truth_line(true,  false,  truth_function);
    print_truth_line(false, true,   truth_function);
    print_truth_line(false, false,  truth_function);
}

template<typename F>
void truth_table_n(int size, F truth_function) {
    static_assert(std::is_invocable_r_v<bool, F, std::vector<bool>>, "Invalid argument to truth table, expected n-ary boolean function");
    if (size > 63) {
        std::cout << "Invalid input size, cannot handle more than 63 booleans for display/sanity reasons" << std::endl;
        return;
    }
    auto result = (unsigned long long int)pow(2.0, size);
    for (unsigned long long int i = 0; i < result; i++) {
        auto boolArr = i;
        std::vector<bool> nextResult;
        for (int j = 0; j < size; j++) {
            nextResult.push_back(!(boolArr & 1));
            boolArr >>= 1;            
        }
        print_truth_line(nextResult, truth_function);
    }
}