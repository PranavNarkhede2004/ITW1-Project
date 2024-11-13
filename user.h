#ifndef USER_H
#define USER_H
#include <string>
using namespace std;
#include "ride.h"


class User{
    public:
    string userID;
    string name;
    string phone;
    string email;
    bool isLoggedIn;
    // Constructor
    User(string id, string n, string p, string e);
    User();
    // Destructor
   ~User();
    // Methods
    void registerUser();
    void loginUser();
    bool checkDuplicateUser(string phone);
    void addUser(string name,string phone,string email);
    friend bool isLoggedIn(User user);
    bool cancelbooking();
};




#endif