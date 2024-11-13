#include<iostream>
#include "ride.h"
#include <thread>  // Include the thread header
#include <chrono> // Include the chrono header
#include "driver.h"
#include "user.h"
#include "history.h"
#include <unistd.h>  // Required for sleep()
// The above two headers are used for creating time delay
using namespace std;

      void welcome(User u){ 
        cout<<"Enter 1 for Login!"<<endl<<"New User click 2 for Register!"<<endl;
        int m;
        cin>>m;
        if(m==1){
            u.loginUser();
        }
        else if(m==2){
            u.registerUser();
        }
        else{
            cout<<"Invalid Input Plz Enter 1 or 2!"<<endl;
            welcome(u);
        }}
int main(){
     ride r;
     Driver  d;
     User u;
     Book b;
   
    int n;
    cout<<"Enter the number:"<<endl;
    cout<<"1.As as Driver:"<<endl;
    cout<<"2.As a User:"<<endl;
    cin>>n;
    cout<<"\t\t\t--------------------Welcome to Btech Cab Services--------------------\t\t\t"<<endl;
    if(n==1){
        cout<<"Enter 1 for driver Registration and 2 for login.";
        cin>>n;
        if(n==1){
            d.DriverRegistration();

        }else if(n==2){
            d.login();
        }else{
            cout<<"Invalid Input"<<endl;
        }
    }

    

    if(n==2){
        int m;
        
        cout<<"Enter 1 for Login!"<<endl<<"New User click 2 for Register!"<<endl;
        cin>>m;
        if(m==1){
            u.loginUser();
        }
        else if(m==2){
            u.registerUser();
        }
        else{
            cout<<"Invalid Input Plz Enter 1 or 2!";
            welcome(u);
        }

        cout<<"Do  you want to book a ride? \n1.Yes 2.No."<<endl;
        cin>>m;
        int cancell;
        if(m==1){
            float  fare;
            fare=r.calculateFare();
            cout<<"Your total fare is "<<fare<<endl;
            d.getdriver(&r);
            b.adduserhistory(&u,&r);           
        }else{
            cout<<"Thank you Visit Again!!"<<endl;
        }
        sleep(7);
        cout<<"Do you want to cancel your ride?(1/0):";
        cin>>cancell;
        if(cancell==1 &&  m==1){
            u.cancelbooking();

        }else{
            cout<<"Continue"<<endl;
        }
        
        if(cancell!=1){
        int k;
        cout<<"Enter 1 to get your Driver details Again."<<endl;
        cin>>k;
            if(k==1 &&  m==1){

            d.getdriver(&r);
        }
        cout<<"Enter 1 to get Estimated time."<<endl;
        cin>>k;
        if(k==1){
            r.estimateTime();
        }

        cout<<"------------------------------------------------------Payment------------------------------------------------------"<<endl<<endl;
        d.payment(&r);
        cout<<"Do you want to display your  ride history? \n1.Yes 2.No"<<endl;
        cin>>k;
        if(k==1 && m==1){
            b.showhistory(&u);

        }else{
            cout<<"Thank you Visit Again!!"<<endl;
        }


        
        }
        
    }

}
       