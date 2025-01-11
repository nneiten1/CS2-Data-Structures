//
//
//
// tests char constructor
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {

        // TEST
        String  str('X');

        // VERIFY
        assert(str == 'X');
    }


    {

        // TEST
        String  str('Z');

        // VERIFY
        assert(str == 'Z');
    }

    {

        // TEST
        String  str(' ');

        // VERIFY
        assert(str == ' ');
    }

    std::cout << "Done testing Char Ctor." << std::endl;

}
