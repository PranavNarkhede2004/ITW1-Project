// *Class: Ride**
//      - Attributes: rideID, source, destination, fare, status (e.g., requested, ongoing, completed)
//      - Methods: calculateFare(), updateStatus(), estimateTime()
//      - Associations: A Ride has one User and one Driver

//      - Responsibilities: Calculate fare, update status, estimate time of arrival

#ifndef RIDE_H 
#define RIDE_H

#include <string>
#include "user.h"
using namespace std;

class ride{
    public:
    
    int rideID;
    string source;
    string destination;
    double fare;
    float distance;

    ride();
    
    
     float calculateFare();
     void updateStatus(string status);
     void estimateTime();
         ~ride();

};




#endif
