//
// test
//
// concat test
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//                          *
//                          *
//                          *
//                          *
//              * * * * * * * * * * * * * *      
//                          *
//                          *    
//                          *    
//                          *
//
//                  Concatenation Tests


int main ()
{
    {
        String  strOne("abcde");
        String strTwo("");

        // TEST
        String result = strOne + strTwo;
        std::cout << "Concat Resul: " << result << std::endl;

        // VERIFY
        assert(strOne == "abcde");
        assert(strTwo == "");
        assert(result == "abcde");
    }
    

    {
        String  strOne("xyz");
        String strTwo;

        // TEST
        String result = strOne + strTwo;
        std::cout << "Concat Resul: " << result << std::endl;

        // VERIFY
        assert(strOne    == "xyz");
        assert(strTwo == "");
        assert(result == "xyz");
    }

    {
        String strOne("hello");
        String strTwo("there");

        // TEST
        String result = strOne + strTwo;

        std::cout << "Result: " << result << std:: endl;

        // VERIFY
        assert(strOne == "hello");
        assert(strTwo == "there");
        assert(result == "hello");
    }

    {
        String strOne("o h i o");
        String strTwo("O H I O");

        // TEST
        String result = strOne + strTwo;
        std::cout << "Result: " << result << std::endl;

        // VERIFY
        assert(strOne == "o h i o");
        assert(strTwo == "O H I O");
        assert(result == "o h i o");
    }
    std::cout << "Done testing Concat." << std::endl;
}