//
//
//
//
//
//

#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
    {
    String a("hello");
    String b("there");
    String c(a = b);

    std::cout << c << std::endl;

    // VERIFY

    assert(a == "there");
    assert(b == "there");
    assert(a == b);

    }

    std::cout << "done testing copy constructor" << std::endl;
}