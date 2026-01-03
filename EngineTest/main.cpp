//
//  main.cpp
//  EngineTest
//
//  Created by Bartłomiej Kuś on 31/12/2025.
//

#include <iostream>
//#include "User.hpp"
#include "UserBase.hpp"


int main(int argc, const char * argv[]) {
    
    
    UserBase base;

    User u("211", "Kacpercper", "2137");
    base.addUser(u);
    
    base.printBase();
    
    std::cout << base.checkUserInCSV(User ("11", "Kacperper", "2137"));
    
    return 0;
}

