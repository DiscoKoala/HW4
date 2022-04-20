/********************************************************
 * Header file for Carwash class that conducts simulation
 *
 * Author: Wesley Johnson
 * Version: 04/23/2022
 *******************************************************/

#ifndef CAR_WASH
#define CAR_WASH

#include"Cars.h"
#include<queue>
#include<string>

class Carwash: Cars{

    private:
    int carwash_time = 3;
    
    public:
    // Default constructor.
    Carwash();

    void occupy(std::queue<Cars> &ls, std::string filename);
    void printTable();
    void printTimes(Cars &car);
    void printTimes(Cars &car, int depart, int wait, int total);
    void setNextStartTime(Cars &car, int depart);
    
};





#endif