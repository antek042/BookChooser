#include "rang.hpp"
#include <iostream>

struct CoutText {
    template<typename T>
    CoutText& operator<<(const T& value){
        std::cout << rang::fg::gray << value << rang::style::reset;
        return *this;
    }
};