#include "stack.hpp"
#include <cassert>
#include <iostream>
#include "../string/string.hpp"
#include "utilities.hpp"
#include "imp.cpp"
int main() {
    
    {
        std::ifstream in("postfix_testset.txt");
        toPostfix(in, std::cout);     
    }
    
    std::cout << "Postfix tests done" << std::endl;
}