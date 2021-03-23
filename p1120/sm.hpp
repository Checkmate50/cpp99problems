#pragma once
#include<variant>

template<typename T>
struct Single {
    T v;
    Single<T>(T av) : v(av) {}
};

template<typename T>
struct Multiple {
    int count;
    T v;
    Multiple<T>(int ac, T av) : count(ac), v(av) {}
};

template<typename T>
void print_single(Single<T>* s) {
    std::cout << "Single " << s->v;
}

template<typename T>
void print_multiple(Multiple<T>* s) {
    std::cout << "Multiple " << s->count << " " << s->v;
}

template<typename T, typename U, typename F1, typename F2>
void print_variant(std::variant<T, U> var, F1 print1, F2 print2) {
    if (auto tcheck = std::get_if<T>(&var))
        print1(*tcheck);
    else
        print2(std::get<U>(var));
}