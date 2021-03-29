#pragma once

#include<iostream>
#include<vector>
#include"print.hpp"

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
    operator bool() const {
        switch (op) {
        case '&': return myand(lhs, rhs);
            break;
        case '|': return myor(lhs, rhs);
            break;
        case '+': return mynand(lhs, rhs);
            break;
        case '-': return mynor(lhs, rhs);
            break;
        case '^': return myxor(lhs, rhs);
            break;
        case '*': return myimpl(lhs, rhs);
            break;
        case '/': return myequ(lhs, rhs);
            break;
        }
        return false; // shouldn't trigger with normal use
    }
};

inline logic_infix_struct logic_infix_object; // this is some seriously dark magic

logic_infix_struct& operator&(const bool& lhs, const logic_infix_struct& rhs);
logic_infix_struct& operator&(const logic_infix_struct& lhs, const bool& rhs);
logic_infix_struct& operator&(const logic_infix_struct& lhs, const logic_infix_struct& rhs);
logic_infix_struct& operator|(const bool& lhs, const logic_infix_struct& rhs);
logic_infix_struct& operator|(const logic_infix_struct& lhs, const bool& rhs);
logic_infix_struct& operator|(const logic_infix_struct& lhs, const logic_infix_struct& rhs);
logic_infix_struct& operator+(const bool& lhs, const logic_infix_struct& rhs);
logic_infix_struct& operator+(const logic_infix_struct& lhs, const bool& rhs);
logic_infix_struct& operator+(const logic_infix_struct& lhs, const logic_infix_struct& rhs);
logic_infix_struct& operator-(const bool& lhs, const logic_infix_struct& rhs);
logic_infix_struct& operator-(const logic_infix_struct& lhs, const bool& rhs);
logic_infix_struct& operator-(const logic_infix_struct& lhs, const logic_infix_struct& rhs);
logic_infix_struct& operator^(const bool& lhs, const logic_infix_struct& rhs);
logic_infix_struct& operator^(const logic_infix_struct& lhs, const bool& rhs);
logic_infix_struct& operator^(const logic_infix_struct& lhs, const logic_infix_struct& rhs);
logic_infix_struct& operator*(const bool& lhs, const logic_infix_struct& rhs);
logic_infix_struct& operator*(const logic_infix_struct& lhs, const bool& rhs);
logic_infix_struct& operator*(const logic_infix_struct& lhs, const logic_infix_struct& rhs);
logic_infix_struct& operator/(const bool& lhs, const logic_infix_struct& rhs);
logic_infix_struct& operator/(const logic_infix_struct& lhs, const bool& rhs);
logic_infix_struct& operator/(const logic_infix_struct& lhs, const logic_infix_struct& rhs);

#define iand   &logic_infix_object&
#define ior    |logic_infix_object|
#define inand  +logic_infix_object+
#define inor   -logic_infix_object-
#define ixor   ^logic_infix_object^
#define iimpl  *logic_infix_object*
#define iequ   /logic_infix_object/

template<typename F>
void print_truth_line(bool l, bool r, F tf) {
    print_bool(l);
    std::cout << "\t";
    print_bool(r);
    std::cout << "\t";
    print_bool(tf(l, r));
    std::cout << std::endl;
}

template<typename F>
void truth_table(F truth_function) {
    print_truth_line(true,  true,   truth_function);
    print_truth_line(true,  false,  truth_function);
    print_truth_line(false, true,   truth_function);
    print_truth_line(false, false,  truth_function);
}