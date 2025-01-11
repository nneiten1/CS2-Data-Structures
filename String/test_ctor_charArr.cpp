//
//
//
//
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        // TEST
        //char x[5] = {'a','b','c','d','e'};
        String  str("abcde");

        // VERIFY
        assert(str == "abcde");
    }

    {
        // TEST
        char x[8] = {'a','b','c','d','e','1','2','9'};
        String  str(x);

        // VERIFY
        assert(str == String(x));
    }

    std::cout << "Done testing Char Array Ctor" << std::endl;
    

}