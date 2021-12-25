// This program gives us the estimated price of a house 

#include <string>
#pragma once 
struct HousePrice {
  std::string address;
  double price;
};


#include "zillow.h"
#include <algorithm>
#include <numeric> 
#include <vector>
#include <iostream>
double get_average_price(std::vector<HousePrice> &pr){
std::vector<double> temp_vec;
double p = 0.0;
for (int i=0; i<pr.size();i++){
  temp_vec.push_back(pr[i].price);
}
for (int i=0; i<temp_vec.size();i++){
   p+= temp_vec[i];
}

  return p/temp_vec.size();
}
