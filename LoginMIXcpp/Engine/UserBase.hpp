//
//  UserBase.h
//  LoginMIXcpp
//
//  Created by Bartłomiej Kuś on 31/12/2025.
//

#ifndef UserBase_hpp
#define UserBase_hpp

#include "User.hpp"
#include <vector>
#include <fstream>
#include <sstream>

class UserBase{
private:
    std::vector<User> users;
public:
    UserBase();
    void update();
    
    
    void addUser(User _user, bool addedToCSV = 0){
        if(checkUserInBase(_user)) return;
        
        users.push_back(_user);
        if(!addedToCSV)
            appendUserToCSV(_user);
    }
    void printBase();
    
    //getters
    std::vector <User> getUsers()   {return users;  }
    
    void loadFromCSV();
    void appendUserToCSV(User& user);
    bool checkUserInBase(User user);
    bool checkUserInCSV(User user);
    
};

#endif /* UserBase_h */
