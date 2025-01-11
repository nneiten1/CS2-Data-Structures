//
//
//
// input tests
//

#include "string.hpp"
#include <cassert>
#include <iostream>
#include <fstream>


int main() {
    std::ifstream inFile;
    inFile.open("input_test.txt");
    
    String one;
    while(inFile >> one){
        std::cout << one << std::endl;
    }
    
    inFile.close();
    std::cout << "Done testing input operator" << std::endl;
}