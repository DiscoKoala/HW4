#include<iostream>
#include<fstream>
#include<queue>

// #include "Cars.h"
#include "Carwash.h"

using namespace std;

const int SIMULATION_END_TIME = 540;
const int WASH_DURATION = 3;

int main(){

    Cars car;
    Carwash wash;
    queue<Cars> carQueue;
    string file = "arrival_time.txt";
    int departureTime, waitTime, totalTime;
    int *nextStart = new int(0);


    wash.occupy(carQueue, file);
    wash.printTable();

    while(!carQueue.empty()){

        // Copy object
        car = carQueue.front();

        // If car arrives after closing.
        if(car.getArriveTime() > SIMULATION_END_TIME){
            wash.printTimes(car);
            carQueue.pop();
            continue;
        };

        wash.setNextStartTime(car, *nextStart);

        // Calculate wait time: start - arrive 
        if(car.getArriveTime() > *nextStart){
            waitTime = 0;
        }else{
            waitTime = car.getStartTime() - car.getArriveTime();
        };

        // Calculate departure time: arrive + wait + duration
        departureTime = car.getStartTime() + waitTime + WASH_DURATION;

        *nextStart = departureTime;

        // Total time: wait + duration
        totalTime = waitTime + WASH_DURATION;

        // Print results.
        wash.printTimes(car, departureTime, waitTime, totalTime);

        carQueue.pop();
    };
     delete nextStart;

    return 0;
};

