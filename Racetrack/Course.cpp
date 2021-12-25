#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>

#include "course.h"


int Course::getRow(Vehicle* v){ //grabs row 
    return v->row;
}

int Course::getCol(Vehicle* v){//grabs col 
    return v->col;
}

char Course::getChar(Vehicle* v){//grabs char  
    return v->repr;
}

Course::Course(){}

Course::Course(std::string course){

    std::string line, parsed;
    std::stringstream stream(course);
    int lineCount = 0, colCount;

    while(std::getline(stream, line)){ 
        parsed = "";
        colCount = 0;
        for(char c: line){
            if(c == '.' || c == '*' || c == 'F' || c == 'S'){
                parsed += c;
                if(c == 'F'){
                    finish_row = lineCount;
                    finish_col = colCount;
                }
                if(c == 'S'){
                    start_row = lineCount;
                    start_col = colCount;
                }
                colCount++;
            }
        }
        if(parsed.length()){
            this->course.push_back(parsed);
            lineCount++;
        }
    }
}

Course::Course(const Course &other){
    this->course = other.course;
    this->finish_row = other.finish_row;
    this->finish_col = other.finish_col;
    this->start_row = other.start_row;
    this->start_col = other.start_col;
}

void Course::AddVehicleToStart(Vehicle* vehicle){ //set up vehicle on the course
    vehicles.push_back(vehicle);
    vehicle->row = start_row;
    vehicle->col = start_col;
}

std::set<Vehicle> Course::VehiclesAtFinish(){ //shows vehicles at finished position
    std::set<Vehicle> result;
    for(Vehicle* v: vehicles){
        if(v->col == finish_col && v->row == finish_row){
            result.insert(*v);
        }
    }
    return result;
}

int Course::ReturnOffTrackVehiclesToStart(){ // any vehicles off course are sent to start position
    int counter = 0;
    for(Vehicle* v: vehicles){
        if(course.at(v->row).at(v->col) == '.'){
            v->row = start_row;
            v->col = start_col;
            counter++;
        }
    }
    return counter;
}

Course& Course::operator = (Course& other){
    this->course = other.course;
    this->finish_row = other.finish_row;
    this->finish_col = other.finish_col;
    this->start_row = other.start_row;
    this->start_col = other.start_col;
    this->vehicles = other.vehicles;
    other.vehicles.clear();
    return *this;
}

std::ostream& operator << (std::ostream &output, const Course &course){ 

    std::vector<std::string> data = course.course;

    for(Vehicle* v: course.vehicles){
        data[Course::getRow(v)][Course::getCol(v)] = Course::getChar(v);
    }

    std::string result;
    result += std::string(data[0].size() + 2, '+') + "\n";

    for(auto line: data){
        result += std::string() + "+" + line + "+\n";
    }
    result += std::string(data[0].size() + 2, '+') + "\n";
    output << result;
    return output;
}
