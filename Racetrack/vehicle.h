#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

class Vehicle{
    private:
        char repr, bearing;
        int row, col; // row, col needs to be private 

    public:
        Vehicle(char c);

        void SetBearing(char b); // actions of the vehicle set public 
        void MoveForward(int n = 1);
        void TurnLeft();
        void TurnRight();

        bool operator < (const Vehicle& other) const;
        bool operator == (const Vehicle& other) const;

        friend std::ostream& operator << (std::ostream &output, const Vehicle &vehicle);

        friend class Course; // allow Course class to access Vehicle class 
};

#endif
