#include "logic.hpp"

bool myand(bool l, bool r) {
    return l && r;
}

bool myor(bool l, bool r) {
    return l || r;
}

bool mynand(bool l, bool r) {
    return !(l && r);
}

bool mynor(bool l, bool r) {
    return !(l || r);
}

bool myxor(bool l, bool r) {
    return l ^ r;
}

bool myimpl(bool l, bool r) {
    return !l || r;
}

bool myequ(bool l, bool r) {
    return l == r;
}

logic_infix_struct& operator&(const bool& lhs, const logic_infix_struct& rhs) {
    logic_infix_object.set_lhs(lhs);
    logic_infix_object.set_op('&');
    return logic_infix_object;
}
logic_infix_struct& operator&(const logic_infix_struct& lhs, const bool& rhs) {
    logic_infix_object.set_rhs(rhs);
    logic_infix_object.set_op('&');
    return logic_infix_object;
}
logic_infix_struct& operator&(const logic_infix_struct& lhs, const logic_infix_struct& rhs) {
    logic_infix_object.set_lhs(lhs);
    logic_infix_object.set_rhs(rhs);
    logic_infix_object.set_op('&');
    return logic_infix_object;
}
logic_infix_struct& operator|(const bool& lhs, const logic_infix_struct& rhs) {
    logic_infix_object.set_lhs(lhs);
    logic_infix_object.set_op('|');
    return logic_infix_object;
}
logic_infix_struct& operator|(const logic_infix_struct& lhs, const bool& rhs) {
    logic_infix_object.set_rhs(rhs);
    logic_infix_object.set_op('|');
    return logic_infix_object;
}
logic_infix_struct& operator|(const logic_infix_struct& lhs, const logic_infix_struct& rhs) {
    logic_infix_object.set_lhs(lhs);
    logic_infix_object.set_rhs(rhs);
    logic_infix_object.set_op('|');
    return logic_infix_object;
}
logic_infix_struct& operator+(const bool& lhs, const logic_infix_struct& rhs) {
    logic_infix_object.set_lhs(lhs);
    logic_infix_object.set_op('+');
    return logic_infix_object;
}
logic_infix_struct& operator+(const logic_infix_struct& lhs, const bool& rhs) {
    logic_infix_object.set_rhs(rhs);
    logic_infix_object.set_op('+');
    return logic_infix_object;
}
logic_infix_struct& operator+(const logic_infix_struct& lhs, const logic_infix_struct& rhs) {
    logic_infix_object.set_lhs(lhs);
    logic_infix_object.set_rhs(rhs);
    logic_infix_object.set_op('+');
    return logic_infix_object;
}
logic_infix_struct& operator-(const bool& lhs, const logic_infix_struct& rhs) {
    logic_infix_object.set_lhs(lhs);
    logic_infix_object.set_op('-');
    return logic_infix_object;
}
logic_infix_struct& operator-(const logic_infix_struct& lhs, const bool& rhs) {
    logic_infix_object.set_rhs(rhs);
    logic_infix_object.set_op('-');
    return logic_infix_object;
}
logic_infix_struct& operator-(const logic_infix_struct& lhs, const logic_infix_struct& rhs) {
    logic_infix_object.set_lhs(lhs);
    logic_infix_object.set_rhs(rhs);
    logic_infix_object.set_op('-');
    return logic_infix_object;
}
logic_infix_struct& operator^(const bool& lhs, const logic_infix_struct& rhs) {
    logic_infix_object.set_lhs(lhs);
    logic_infix_object.set_op('^');
    return logic_infix_object;
}
logic_infix_struct& operator^(const logic_infix_struct& lhs, const bool& rhs) {
    logic_infix_object.set_rhs(rhs);
    logic_infix_object.set_op('^');
    return logic_infix_object;
}
logic_infix_struct& operator^(const logic_infix_struct& lhs, const logic_infix_struct& rhs) {
    logic_infix_object.set_lhs(lhs);
    logic_infix_object.set_rhs(rhs);
    logic_infix_object.set_op('^');
    return logic_infix_object;
}
logic_infix_struct& operator*(const bool& lhs, const logic_infix_struct& rhs) {
    logic_infix_object.set_lhs(lhs);
    logic_infix_object.set_op('*');
    return logic_infix_object;
}
logic_infix_struct& operator*(const logic_infix_struct& lhs, const bool& rhs) {
    logic_infix_object.set_rhs(rhs);
    logic_infix_object.set_op('*');
    return logic_infix_object;
}
logic_infix_struct& operator*(const logic_infix_struct& lhs, const logic_infix_struct& rhs) {
    logic_infix_object.set_lhs(lhs);
    logic_infix_object.set_rhs(rhs);
    logic_infix_object.set_op('*');
    return logic_infix_object;
}
logic_infix_struct& operator/(const bool& lhs, const logic_infix_struct& rhs) {
    logic_infix_object.set_lhs(lhs);
    logic_infix_object.set_op('/');
    return logic_infix_object;
}
logic_infix_struct& operator/(const logic_infix_struct& lhs, const bool& rhs) {
    logic_infix_object.set_rhs(rhs);
    logic_infix_object.set_op('/');
    return logic_infix_object;
}
logic_infix_struct& operator/(const logic_infix_struct& lhs, const logic_infix_struct& rhs) {
    logic_infix_object.set_lhs(lhs);
    logic_infix_object.set_rhs(rhs);
    logic_infix_object.set_op('/');
    return logic_infix_object;
}