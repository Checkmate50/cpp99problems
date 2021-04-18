#include "logic.hpp"

#define UNUSED(expr) do { (void)(expr); } while (0)

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

and_infix_struct& operator&(const bool& lhs, const logic_infix_struct& rhs) {
    UNUSED(rhs);
    and_infix_object.set_lhs(lhs);
    return and_infix_object;
}
bool operator&(const logic_infix_struct& lhs, const bool& rhs) {
    UNUSED(lhs);
    and_infix_object.set_rhs(rhs);
    return (bool)and_infix_object;
}
or_infix_struct& operator|(const bool& lhs, const logic_infix_struct& rhs) {
    UNUSED(rhs);
    or_infix_object.set_lhs(lhs);
    return or_infix_object;
}
bool operator|(const logic_infix_struct& lhs, const bool& rhs) {
    UNUSED(lhs);
    or_infix_object.set_rhs(rhs);
    return (bool)or_infix_object;
}
nand_infix_struct& operator+(const bool& lhs, const logic_infix_struct& rhs) {
    UNUSED(rhs);
    nand_infix_object.set_lhs(lhs);
    return nand_infix_object;
}
bool operator+(const logic_infix_struct& lhs, const bool& rhs) {
    UNUSED(lhs);
    nand_infix_object.set_rhs(rhs);
    return (bool)nand_infix_object;
}
nor_infix_struct& operator-(const bool& lhs, const logic_infix_struct& rhs) {
    UNUSED(rhs);
    nor_infix_object.set_lhs(lhs);
    return nor_infix_object;
}
bool operator-(const logic_infix_struct& lhs, const bool& rhs) {
    UNUSED(lhs);
    nor_infix_object.set_rhs(rhs);
    return (bool)nor_infix_object;
}
xor_infix_struct& operator^(const bool& lhs, const logic_infix_struct& rhs) {
    UNUSED(rhs);
    xor_infix_object.set_lhs(lhs);
    return xor_infix_object;
}
bool operator^(const logic_infix_struct& lhs, const bool& rhs) {
    UNUSED(lhs);
    xor_infix_object.set_rhs(rhs);
    return (bool)xor_infix_object;
}
impl_infix_struct& operator*(const bool& lhs, const logic_infix_struct& rhs) {
    UNUSED(rhs);
    impl_infix_object.set_lhs(lhs);
    return impl_infix_object;
}
bool operator*(const logic_infix_struct& lhs, const bool& rhs) {
    UNUSED(lhs);
    impl_infix_object.set_rhs(rhs);
    return (bool)impl_infix_object;
}
equ_infix_struct& operator/(const bool& lhs, const logic_infix_struct& rhs) {
    UNUSED(rhs);
    equ_infix_object.set_lhs(lhs);
    return equ_infix_object;
}
bool operator/(const logic_infix_struct& lhs, const bool& rhs) {
    UNUSED(lhs);
    equ_infix_object.set_rhs(rhs);
    return (bool)equ_infix_object;
}