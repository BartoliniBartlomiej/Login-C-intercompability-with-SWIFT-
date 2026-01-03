//
//  User.h
//  LoginMIXcpp
//
//  Created by Bartłomiej Kuś on 31/12/2025.
//

#ifndef User_hpp
#define User_hpp

#include <string>
#include <iostream>

class User{
private:
    std::string login;
    std::string pin;
    std::string id;

public:
    User(std::string _id, std::string _login, std::string _pin){
        id = _id;
        login = _login;
        pin = _pin;
        //std::cout << "User " << login << " created. \n";
    }
    
    //getters
    std::string getLogin() {return login;}
    std::string getPin() {return pin;}
    std::string getId() {return id;}
};

#endif /* User_h */
