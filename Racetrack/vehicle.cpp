#include "vehicle.h"
#include <stdexcept>


Vehicle::Vehicle(char c){
    repr = c;
}

void Vehicle::SetBearing(char b){
    if(b == 'N' || b == 'E' || b == 'S' || b == 'W'){
        bearing = b;
        return;
    }
    throw std::invalid_argument("Bearing must be 'N' 'E' 'S' or 'W'."); // if N,E,S,W is not declared, throw exception 
}

void Vehicle::MoveForward(int n){ // describes foward movement 
    switch(bearing){
        case 'N':
            row -= n;
            return;
        case 'E':
            col += n;
            return;
        case 'S':
            row += n;
            return;
        case 'W':
            col -= n;
            return;
    }
}

void Vehicle::TurnLeft(){ // describes left movement 
    switch(bearing){
        case 'N':
            bearing = 'W';
            return;
        case 'E':
            bearing = 'N';
            return;
        case 'S':
            bearing = 'E';
            return;
        case 'W':
            bearing = 'S';
            return;
    }
}

void Vehicle::TurnRight(){// describes right movement 
    switch(bearing){
        case 'N':
            bearing = 'E';
            return;
        case 'E':
            bearing = 'S';
            return;
        case 'S':
            bearing = 'W';
            return;
        case 'W':
            bearing = 'N';
            return;
    }
}

bool Vehicle::operator < (const Vehicle& other) const{ //comparative stored as bool 
    return repr < other.repr;
}

bool Vehicle::operator == (const Vehicle& other) const{//comparative stored as bool 
    return repr == other.repr;
}

std::ostream& operator << (std::ostream &output, const Vehicle &vehicle){ //send information to output
    output << vehicle.repr;
    return output;
}
