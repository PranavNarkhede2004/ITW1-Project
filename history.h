// *Class: Ride**
//      - Attributes: rideID, source, destination, fare, status (e.g., requested, ongoing, completed)
//      - Methods: calculateFare(), updateStatus(), estimateTime()
//      - Associations: A Ride has one User and one Driver

//      - Responsibilities: Calculate fare, update status, estimate time of arrival

#ifndef Book_H 
#define Book_H
#include "ride.h"
#include "user.h"
#include <string>
class Book:public User,public ride{
    public:
    Book();
    void adduserhistory(User *U,ride *r);
    void showhistory(User *U);
    
};




#endif