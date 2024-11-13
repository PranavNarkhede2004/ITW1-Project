
// // **Class: User**
// //      - Attributes: name, phone, email, location,UserID
// //      - Methods: register(), login(), logout()
// //      - Associations: User can book a Ride

#include "user.h"
#include"ride.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

User::User(string id, string n, string p, string e){
    this->userID = id;
    this->name = n;
    this->phone = p;
    this->email = e;
}
User::User(){};
User::~User(){};

void User::registerUser() {
    string name, phone, email;
    cout << "Enter Phone Number: ";
    cin >> phone;

    // Check for duplicate user
    if (User::checkDuplicateUser(phone)) {
        // If the user already exists, do not register again
        cout << "User is already registered in the system." << endl;
        return;
    }

    // Register new user
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Email: ";
    cin >> email;

    User::addUser(name, phone, email);
    cout << "User Registered Successfully" << endl;
}

bool User::checkDuplicateUser(string phone) {
    // Check if the user already exists in the database
    ifstream file("user.txt");  // Open the file in read mode
    string line;

    // Read each line from the file
    while (getline(file, line)) {
        stringstream ss(line);
        string userid, name, phone1, email;
        ss >> userid >> name >> phone1 >> email;

        // Trim any leading or trailing whitespace from phone1
        phone1.erase(phone1.find_last_not_of(" \n\r\t") + 1);

        // Check if the given phone matches the phone in the file
        if (phone == phone1) {

        this->email = email;
        this->name = name;
        this->userID = userid;
        this->phone = phone;
            cout << "Existing UserID is: " << userid << endl;
            return true;
        }
    }
    // If no match is found, the user is not registered
    return false;
}

void User::addUser(string name, string phone, string email) {
    // Add a new user to the database
    ofstream file("user.txt", ios::app);  // Append mode

    string r;
    r.resize(8);
    int l = name.size();
    if (l <= 4) {
        for (int i = 0; i < l; i++) {
            r[i] = name[i];
        }

        for (int i = l; i < 8; i++) {
            r[i] = phone[i - l];
        }
    } else {
        for (int i = 0; i < 4; i++) {
            r[i] = name[i];
        }
        for (int i = 4; i < 8; i++) {
            r[i] = phone[i - 4];
        }
    }
    this->email = email;
    this->name = name;
    this->userID = r;
    this->phone = phone;

    // Write the new user's details to the file
    file << r << " " << name << " " << phone << " " << email << endl;
}



void User :: loginUser(){
    string phone;
    string CustID;
    cout<<"Enter Phone Num:";
    cin>>phone;
    cout<<"Enter Customer ID:";
    cin>>CustID;

    ifstream file("user.txt");  // Open the file in read mode
    string line;
    bool  found=false;
     string name1,phone1,email;
      string userid;

     while(getline(file, line)) {
        // Compare 
        stringstream ss(line);
       
       
        ss >> userid >> name1 >> phone1 >> email;
        auto trim = [](string &str) {
            str.erase(0, str.find_first_not_of(" \n\r\t")); // Trim leading whitespace
            str.erase(str.find_last_not_of(" \n\r\t") + 1); // Trim trailing whitespace
        };
        trim(phone1);
        trim(phone);
        trim(CustID);
        trim(userid);
        if(userid==CustID &&  phone1==phone){
            cout<<"Login Successfull"<<endl;
            found=true;
            break;
        }
       

        
}
if(found==true){
    this->email = email;
    // cout<<name<<endl;
    this->name = name1;
    this->userID = userID;
    this->phone = phone;
}
if(found==false){
    
        
            cout<<"Invalid Credential please register."<<endl; 

            registerUser();
        
}
}
bool User::cancelbooking(){
    bool flag;
    flag=false;
    return flag;
}



