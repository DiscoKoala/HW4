/********************************************************
 * Implementation of Carwash functions
 *
 * Author: Wesley Johnson
 * Version: 04/23/2022
 *******************************************************/

#include<fstream>
#include<iostream>
#include<string>

#include"Carwash.h"

using namespace std;

Carwash::Carwash(){};

void Carwash::occupy(std::queue<Cars> & ls, string fileName){

    fstream inFile;
    string line;
    int carCount = 1;

    inFile.open(fileName, std::ios::in);
    
    // Check if file properly opened. If not, throw exception.
    try{
        if(!inFile.is_open()){
            throw(fileName);
        }
        else{
            // Loop through input file.
            while(!inFile.eof()){
                getline(inFile, line);

                // Instantiate car object.
                Cars car(carCount, stoi(line));

                // Push object to queue.
                ls.push(car);
                carCount++;
            };
        };
    }catch(string file){
        cout << "Unable to open " << file << ".";
    };
};

void Carwash::printTable(){

    printf("%-*s", 13, "Car Number");
    printf("%-*s", 15, "Arrival Time");
    printf("%-*s", 11, "Car Wash");
    printf("%-*s", 18, "Departure Time");
    printf("%-*s", 13, "Wait Time");
    printf("%-*s", 14, "Total");
    std::cout << "\n";
    printf("%*s", 37, "Start Time");
    printf("%*s", 38, "Time");
    std::cout << "\n";
};

void Carwash::printTimes(Cars &car){

    printf("% *d", 5, car.getCarNum());
    printf("% *d", 13, car.getArriveTime());
    printf("%*s", 14, "           Car arrived after closing time and was not served");
    std::cout << "\n";
};

void Carwash::printTimes(Cars &car, int depart, int wait, int total){

    printf("% *d", 5, car.getCarNum());
    printf("% *d", 13, car.getArriveTime());
    printf("% *d", 14, car.getStartTime());
    printf("% *d", 14, depart);
    printf("% *d", 16, wait);
    printf("% *d", 11, total);
    std::cout << "\n";
};

void Carwash::setNextStartTime(Cars &car, int depart){
   
    if(car.getArriveTime() >= car.getStartTime()){
            car.setStartTime(car.getArriveTime());
        }else{
            car.setStartTime(depart);
        };
};
