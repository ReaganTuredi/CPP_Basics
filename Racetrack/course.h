#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <vector>
#include <string>
#include <set>

#include "vehicle.h"

class Course{
    private:
        std::vector<std::string> course;
        int start_row, start_col;
        int finish_row, finish_col;
        std::vector<Vehicle*> vehicles;

        static int getRow(Vehicle* v); // row, col, char part of private 
        static int getCol(Vehicle* v);
        static char getChar(Vehicle* v);

        Course();

    public:
        Course(std::string course); 
        Course(const Course &other);     //copy constructor

        void AddVehicleToStart(Vehicle* vehicle);
        std::set<Vehicle> VehiclesAtFinish();
        int ReturnOffTrackVehiclesToStart();


        Course& operator = (Course& other);  // assignment copy
        friend std::ostream& operator << (std::ostream &output, const Course &vehicle);
};

#endif
