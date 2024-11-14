#include<iostream>
using namespace std;
#include "history.h"
#include <string>
#include <fstream>
#include <sstream>
// histor.cpp
Book::Book(){};
void Book::adduserhistory(User *u,ride *r){
    //adding to database
    ofstream file("history.txt",ios::app);  //append mode
    bool flag=true;
    file<<u->name<<" "<<u->phone<<" "<<r->fare<<" "<<r->source<<" "<<r->destination<<" "<<flag<<endl;
} 


void Book::showhistory(User *u) {
    ifstream file("history.txt");
    if (!file.is_open()) {
        cout << "Error opening history file." << endl;
        return;
    }

    string line;
    bool recordFound = false;
    cout << "History of Bookings for Mr. " << u->name << endl;

    // Read each line from the file
    while (getline(file, line)) {
        stringstream ss(line);
        string nam, mono, fareprice, s, d;
        bool y;

        // Extract data from the line
        ss >> nam >> mono >> fareprice >> s >> d >> y;

        // Check if the phone number matches the user's phone number
        if (u->phone == mono) {
            cout << nam << " " << mono << " " << fareprice << " " << s << " " << d << " " << (y ? "Completed" : "Pending") << endl;
            recordFound = true;
        }
    }

    // Close the file after reading
    file.close();

    // If no records were found, display a message
    if (!recordFound) {
        cout << "No records found." << endl;
    }
}