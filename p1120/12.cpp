#include<iostream>
#include<utility>
#include<variant>
#include"sm.hpp"

// (**) Decode a run-length encoded list.

// Given a run-length code list generated as specified in problem 11. Construct its uncompressed version.

template<typename T, size_t N>
std::pair<T*, int> decodeModified(std::variant<Single<T>*, Multiple<T>*> (&v)[N]) {
    int size = 0;
    for (size_t i = 0; i < N; i++) {
        if (auto temp = std::get_if<Multiple<T>*>(&v[i]))
            size += (*temp)->count;
        else
            size++;
    }
    T* lst = new T[size];
    int index = 0;
    for (size_t i = 0; i < N; i++) {
        if (auto n1 = std::get_if<Multiple<T>*>(&v[i])) {
            for (int j = 0; j < (*n1)->count; j++) {
                lst[index] = (*n1)->v;
                index++;
            }
        }
        else {
            auto n2 = std::get<Single<T>*>(v[i]);
            lst[index] = n2->v;
            index++;
        }
    }
    std::pair<T*, int> to_return(lst, size);
    return to_return;
}

int main() {
    //[Multiple 4 'a',Single 'b',Multiple 2 'c',
     //   Multiple 2 'a',Single 'd',Multiple 4 'e']
    Multiple<char>* first = new Multiple(4, 'a');
    Single<char>* second = new Single('b');
    Multiple<char>* third = new Multiple(2, 'c');
    Multiple<char>* fourth = new Multiple(2, 'a');
    Single<char>* fifth = new Single('d');
    Multiple<char>* sixth = new Multiple(4, 'e');
    std::variant<Single<char>*, Multiple<char>*> test[6] = 
        {first, second, third, fourth, fifth, sixth};
    auto result = decodeModified(test);
    for (int i = 0; i < result.second; i++) {
        std::cout << result.first[i];
    }
    std::cout << std::endl;
}