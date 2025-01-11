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

        String  str("a");
        String strTwo("a");
        // TEST
        bool result = (str == strTwo);

        // VERIFY
        assert(str    == "a");
        assert(strTwo == "a");
        assert(result == true);
    }


    {

        String  str("a");
        String strTwo("b");
        // TEST
        bool result = (str == strTwo);

        // VERIFY
        assert(str    == "a");
        assert(strTwo == "b");
        assert(result == false);
    }


    {

        String  str("a1b23c");
        String strTwo("a1b23c");
        // TEST
        bool result = (str == strTwo);

        // VERIFY
        assert(str    == "a1b23c");
        assert(strTwo == "a1b23c");
        assert(result == true);
    }


    {

        String  str("100");
        String strTwo("a");
        // TEST
        bool result = (str == strTwo);

        // VERIFY
        assert(str    == "100");
        assert(strTwo == "a");
        assert(result == false);
    }

    {
        String str("123456789");
        String strTwo("123456789");

        // TEST
        bool result = (str == strTwo);

        // VERIFY
        assert(str == "123456789");
        assert(strTwo == "123456789");
        assert(result == true);
    }
    
    std::cout << "Done testing Equality." << std::endl;
}