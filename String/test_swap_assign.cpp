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
        String str("test1");
        String strTwo("test2");
        String result = str + strTwo;

        std::cout << "Swapped " << result << std::endl;

        // VERIFY
        assert(str == "test1");
        assert(strTwo == "test2" );

    }

    std::cout << "Done testing swap." << std::endl;



}