// Driver.h
// In your case, DRIVER_H ensures that the Driver class 
// (or any other content in driver.h) is included just once during compilation.
#ifndef DRIVER_H
#define DRIVER_H
#include "ride.h"
#include <string>
using namespace std;

class Driver:public ride{
    public:
        string driverID;
        string name;
        string mobile_no;
        string licenseNumber;
        string vehicleDetails;
        string location;
        string rating;


        // Constructor;
        Driver(string D_id, string n, string m, string LicNo, string vDetails, string Loc, string rat);
        Driver();
        // Methods
        void display();
        void login();
        void getdriver(ride *r);
        void display(int t);
        void payment(ride *r);
        void DriverRegistration();
        void addDriverToDatabase();
        bool checkDuplicateDriver(const string &id,const string &phone);
        void updateLocation(ride *ride);
};




#endif
