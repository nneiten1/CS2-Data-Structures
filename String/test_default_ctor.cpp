//
//
//
//
//

#include "string.hpp"
#include <iostream>
#include <cassert>

//===========================================================================
 
 int main() {

    {
    // TEST
        String  str;

        // VERIFY
        assert(str == '\0');
    }
    
    std::cout << "Done testing Default Constructor." << std::endl;
 }
