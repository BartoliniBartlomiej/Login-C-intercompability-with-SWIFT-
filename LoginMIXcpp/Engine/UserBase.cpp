//
//  UserBase.cpp
//  LoginMIXcpp
//
//  Created by Bartłomiej Kuś on 31/12/2025.
//
#include "UserBase.hpp"

UserBase::UserBase(){
    loadFromCSV();
}

//void UserBase::addUser(User _user, bool addedToCSV = 0) {
//    users.push_back(_user);
//    if(!addedToCSV)
//        appendUserToCSV(_user);
//}

void UserBase::printBase(){
    for(auto u : users)
    {
        std::cout << u.getLogin() << "|" << u.getPin() << std::endl;
    }
}

void UserBase::loadFromCSV(){
    const std::string& filePath = "/Users/bartek/Coding/SWIFT/LoginMIXcpp/LoginMIXcpp/UserBase/users.csv";
    std::ifstream file(filePath);
    if (!file.is_open()) {
        return; // silently no-op if file can't be opened
    }
    
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id, username, password;
        if (std::getline(ss, id, ',') && std::getline(ss, username, ',') && std::getline(ss, password)) {
            User u(id, username, password);
            addUser(u,1);
        }
    }
}

void UserBase::appendUserToCSV(User& user) {
    
    const std::string& filePath = "/Users/bartek/Coding/SWIFT/LoginMIXcpp/LoginMIXcpp/UserBase/users.csv";
    std::ofstream out(filePath, std::ios::app);
    if (!out.is_open()) {
        return; // silently no-op if file can't be opened
    }
    // Append as: id,login,password (pin)
    // Assuming User has getters: getId(), getLogin(), getPin()
    out << user.getId() << "," << user.getLogin() << "," << user.getPin() << "\n";
}

// if user IS already in base -> return 1,
// if NOT -> return 0
bool UserBase::checkUserInBase(User user){
    
    for(auto u : users){
        if(user.getLogin() == u.getLogin())
            return true;
    }
    
    return false;
}

bool UserBase::checkUserInCSV(User user)
{
    std::ifstream file("/Users/bartek/Coding/SWIFT/LoginMIXcpp/LoginMIXcpp/UserBase/users.csv");
    if (!file.is_open())
        return false;

    std::string line;
    std::getline(file, line); // pomijamy nagłówek

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string id, login, password;

        std::getline(ss, id, ',');
        std::getline(ss, login, ',');
        std::getline(ss, password, ',');

        if (login == user.getLogin())
            return true;
    }

    return false;
}
