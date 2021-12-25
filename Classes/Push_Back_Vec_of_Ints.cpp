//This program supports the "push_back" and "at" methods of a vector of ints

#include <vector>
#pragma once
struct PythonicIntVector{
        std::vector<int> data;
        int at(int index);
        void push_back(int number);
};

#include "PythonicIntVector.h"
#include <stdexcept>

int PythonicIntVector::at(int index){
    if(index >= 0){
        if (index >= (int)data.size()){
            throw std::out_of_range("Invalid indicies");
        }
        return data.at(index);
    }
    else{
        // negative index
        index = (-index) - 1;    // turn -1 to 0, -2 to 1, ...
        if (index >= (int)data.size()){
            throw std::out_of_range("out of range.");
        }
        return data.at(data.size() - 1 - index);
    }
}
void PythonicIntVector::push_back(int number){
    data.push_back(number);
}
