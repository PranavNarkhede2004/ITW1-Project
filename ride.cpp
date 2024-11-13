#include<iostream>
#include<fstream>
#include<sstream>
#include "ride.h"
#include <unistd.h>  // Required for sleep()

using namespace std;
ride::ride(){};
ride::~ride(){};
float ride::calculateFare(){
        float fare;
        int s,d;
        sleep(2);
        cout << "Select Pickup point:\n"
     << "1. IIITN           \t  2. Sootgirni      \t  3. MNLU          \t  4. Borkhedi\n"
     << "5. Mohgaon         \t  6. Bothali        \t  7. Dongargaon    \t  8. Suretech_Hospital\n"
     << "9. Jamtha          \t 10. Khapri         \t 11. Chinch_bhavan \t 12. South_Airport\n"
     << "13. Ujjawal_Nagar  \t 14. Sneh_Nagar     \t 15. Chhtrapati_Square \t 16. Ajni_Square\n"
     << "17. Rahate_Square  \t 18. Lokmat_Square  \t 19. Panchsheel_Square \t 20. Sitaburdi\n";

        cin>>s;
        sleep(2);
        cout << "Select Dropping point:\n"
     << "1. IIITN           \t  2. Sootgirni      \t  3. MNLU          \t  4. Borkhedi\n"
     << "5. Mohgaon         \t  6. Bothali        \t  7. Dongargaon    \t  8. Suretech_Hospital\n"
     << "9. Jamtha          \t 10. Khapri         \t 11. Chinch_bhavan \t 12. South_Airport\n"
     << "13. Ujjawal_Nagar  \t 14. Sneh_Nagar     \t 15. Chhtrapati_Square \t 16. Ajni_Square\n"
     << "17. Rahate_Square  \t 18. Lokmat_Square  \t 19. Panchsheel_Square \t 20. Sitaburdi\n";

        cin>>d;

        // exception handling
        if(s==d){
                cout<<"Source and Destination are same\nPlease select Different locations\n";
                calculateFare();
        }
        else{
                //open file
                ifstream file("locations.txt");
                if(file.is_open()){
                        string line,line2;
                
                       if(s>d){
                        for(int i=1;i<=d;i++){
                                getline(file,line);
                        }
                        stringstream ss(line);
                        float sc,dc;
                        ss>>this->destination>>dc;
                        for(int i=d+1;i<=s;i++){
                                getline(file,line2);
                        }
                        stringstream ss1(line2);
                        ss1>>this->source>>sc;
                        int basic_fare=50;
                        this->distance=sc-dc;
                        this->fare=(sc-dc)*30;
                        if(this->fare<100){
                                this->fare+=basic_fare;
                        }
                       }
                       else{
                        for(int i=1;i<=s;i++){
                                getline(file,line);
                        }
                        stringstream ss2(line);
                        float sc,dc;
                        ss2>>this->source>>sc;
                        for(int i=s+1;i<=d;i++){
                                getline(file,line2);
                        }
                        stringstream ss3(line2);
                        ss3>>this->destination>>dc;
                        int basic_fare=50;
                        this->distance=dc-sc;
                        this->fare=(dc-sc)*30;
                        if(this->fare<100){
                                this->fare+=basic_fare;
                        }
                       }
                       return this->fare;
        }
}//Fare is not displayed , please display it while using Main

}

void ride::estimateTime(){
        int standard_time=5 ;//5 min 
        float total_time=standard_time*this->distance;
        sleep(1);
        cout<<"Congratulations, Cab Booked Successfully !\n";
        sleep(1);
        cout<<"Estimated Time Of Journey is :"<<(int)total_time/60<<" Hours "<<total_time-(int)(total_time/60)*60<<" Min\n";
        sleep(1);
        cout<<"Time May Vary According to Traffic Conditions !\n Happy  Journey !\n";
        sleep(1);
        cout << "Kindly Wait while we complete the Journey from Source to Destination ...." <<endl;
       sleep(7);
        cout << "Done!" <<endl;


}