/********************************************************
 * Car class definitions / implementation.
 *
 * Author: Wesley Johnson
 * Version: 04/23/2022
 *******************************************************/

#include<iostream>
#include<fstream>
#include<queue>

#include "Cars.h"

Cars::Cars(){};

Cars::Cars(int car_num, int arrival){
    car_number = car_num;
    arrival_time = arrival;
};

int Cars::getCarNum(){
    return car_number;
};

int Cars::getArriveTime(){
    return arrival_time;
};

int Cars::getStartTime(){
    return start_time;
};

void Cars::setCarNum(int carNum){
    car_number = carNum;
};
void Cars::setArriveTime(int time_){
    arrival_time = time_;
};
void Cars::setStartTime(int time_){
    start_time = time_;
};

