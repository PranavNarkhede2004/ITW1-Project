// Driver.cpp
#include "driver.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include <unistd.h>  // Required for sleep()

using namespace std;


// Constructor
Driver::Driver(string D_id, string n, string m, string LicNo, string vDetails, string Loc, string rat) {
    driverID = D_id;
    name = n;
    mobile_no = m;
    licenseNumber = LicNo;
    vehicleDetails = vDetails;
    location = Loc;
    rating = rat;
}
Driver::Driver(){};
void Driver::display(int t){
    cout<<"Driver's Info:"<<endl;
    cout <<"Name:" << name <<endl<< "Mobile:" << mobile_no
         <<endl<< "Vehicle:" << vehicleDetails
         <<endl<< "Rating:" <<rating  << endl;
}

void Driver::display() {
    cout<<"Driver's Info:"<<endl;
    cout << "ID:" << driverID <<endl<< "Name:" << name <<endl<< "Mobile:" << mobile_no
         <<endl<< "License:"<< licenseNumber <<endl<< "Vehicle:" << vehicleDetails
         <<endl<< "Location:" << location <<endl<< "Rating:" <<rating  << endl;
}


bool Driver::checkDuplicateDriver(const string& id, const string& phone) {
    ifstream file("driver.txt");
    if (!file.is_open()) {
        cout << "Error opening driver database." << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string existingId, existingName, existingPhone, existingLicense, existingCar, existingLocation, existingRating;

        ss >> existingId >> existingName >> existingPhone >> existingLicense >> existingCar >> existingLocation >> existingRating;

        // Check if the driver ID and phone number match
        if (existingId == id || existingPhone == phone) {
            cout << "Driver already registered with ID: " << existingId << " or Phone: " << existingPhone << endl;
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void Driver::addDriverToDatabase() {
    ofstream file("driver.txt", ios::app); // Open in append mode
    if (!file.is_open()) {
        cout << "Error opening driver database for writing." << endl;
        return;
    }

    // Write the driver's details to the file
    file << driverID << " " << name << " " << mobile_no << " " << licenseNumber << " " << vehicleDetails << " " << location << " " << rating << endl;

    file.close();
    cout << "Driver registered successfully!" << endl;
}

void Driver::DriverRegistration() {
    cout << "Enter Driver ID: ";
    cin >> driverID;
    cout << "Enter Phone Number: ";
    cin >> mobile_no;
   

    // Check if the driver is already registered
    if (!checkDuplicateDriver(driverID, mobile_no)) {
        // Add the new driver to the database
        addDriverToDatabase();
         cout << "Enter Name: ";
    cin >> name;
    cout << "Enter License Number: ";
    cin >> licenseNumber;
    cout << "Enter Car Model: ";
    cin >> vehicleDetails;
    cout << "Enter Location: ";
    cin >> location;
    cout << "Enter Rating (out of 5): ";
    cin >> rating;
    } else {
        cout << "Registration failed. Driver already exists in the database." << endl;
    }
}

void Driver::getdriver(ride *r) {
    ifstream file("driver.txt");
    string line;
    int flag = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        string name, license, car, location;
        string id_str, phone, rating_str;

        // Read data from the file (space-separated)
        ss >> id_str >> name >> phone >> license >> car >> location >> rating_str;

        // Get the source location from the ride
        string loc = r->source;

        // Trim whitespace from location and loc
        auto trim = [](string &str) {
            str.erase(0, str.find_first_not_of(" \n\r\t")); // Trim leading whitespace
            str.erase(str.find_last_not_of(" \n\r\t") + 1); // Trim trailing whitespace
        };
        trim(location);
        trim(loc);

        // Compare location with loc
        if (!location.compare(loc) ) {
            Driver d(id_str, name, phone, license, car, loc, rating_str);
            cout << "Wait 5 Minutes, the driver is on the way...." << endl;
            cout << "---------------------------------------------------------" << endl << endl << endl;
            sleep(5);
            d.display(1);
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        cout << "No drivers available in the specified location." << endl;
    }
}

void Driver::payment(ride *r){
    cout<<"Select payment  method:"<<endl;
    cout<<"1.Cash Payment"<<endl;
    cout<<"2.Online"<<endl;
    int a;
    cin>>a;
    if(a==1){
        cout<<"Give the Cash to the driver"<<endl;
        cout<<"You need to pay 30Rs as Handling Charges."<<endl;
        cout<<"Total fare: "<<r->fare+30.00<<endl;
        sleep(7);
        cout<<"Payment Successful.";
        sleep(5);

    }else{
        cout<<"Total Fare: "<<r->fare<<endl;
        cout<<"Make the payment on following UPI Id:";
        string name1;
        
        cout<<"Btechcabservices@okaxis"<<endl;
        sleep(7);
        cout<<"Payment Successful."<<endl;
        sleep(5);
    }
      int flag=0;

      cout<<"Do you want to give tip:"<<endl;
      cout<<"1.Yes"<<endl;
      cout<<"2.No"<<endl;
      cin>>flag;
      if(flag==1){
        cout<<"Enter the tip amount(10/20/50):"<<endl;
        int tip;
        cin>>tip;
        cout<<"Thanks For giving tip."<<endl;
      }
}



void Driver::login(){
    int D_id;
    cout<<"Enter your id:";
    cin>>D_id;

     ifstream file("driver.txt");
    string line;
    int flag=0;
   
    while(getline(file,line)){
        stringstream ss(line);
        string name, license, car, location;
        string id_str, phone, rating_str;
        int id;
        float rating;

        // Read data from the file (space-separated)
        ss >> id_str >> name >> phone >> license >> car >> location >> rating_str;

        // Convert string to the appropriate types
        id = stoi(id_str);             // Convert driverID from string to int
        rating = stof(rating_str);     // Convert rating from string to float
        
        if(id==D_id){
           this->driverID=id;
           this->name=name;
           this->mobile_no=phone;
           this->licenseNumber=license;
           this->vehicleDetails=car;
           this->location=location;
           this->rating=rating;
        cout<<"Login Successfully:"<<endl;
        flag=1;
        break;
        }
        
    }
    
}