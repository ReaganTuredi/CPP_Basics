// This program converts a pointer to a double using classes.

#pragma once
struct SafePtrToDouble{
        double* ptr;
        double& Dereference();
        double* Value();
        SafePtrToDouble(double *ptr);
};


#include "SafePtrToDouble.h"
#include <stdexcept>

double& SafePtrToDouble::Dereference(){
    if (ptr) 
    return *ptr;
    throw std::logic_error("nullptr err.");
}

double* SafePtrToDouble::Value(){
    return ptr;
}

SafePtrToDouble::SafePtrToDouble(double *ptr){
    this->ptr = ptr;
}
