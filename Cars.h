/********************************************************
 * Car class for instantiating objects for queue
 *
 * Author: Wesley Johnson
 * Version: 04/23/2022
 *******************************************************/

#ifndef CARS
#define CARS

class Cars{
    private:
        int car_number, arrival_time, start_time;

    public:
        Cars();
        Cars(int car_num, int arrival);
        
        //Getters
        int getCarNum();
        int getArriveTime();
        int getStartTime();
        

        //Setters
        void setCarNum(int carNum);
        void setArriveTime(int time_);
        void setStartTime(int start_);
        

};


#endif