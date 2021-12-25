// This function takes a map of strings (names) and ints (owned pets), and returns the number of people with at least one pet

#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>


int FriendsWithPets(const std::map<std::string,int> &map){
 std::vector<double> vecOfValues;
                                                                            
std::transform( map.begin(),map.end(),std::back_inserter(vecOfValues),[](auto &kv){ return kv.second;});
// found from https://stackoverflow.com/questions/771453/copy-map-values-to-vector-in-stl
vecOfValues.erase(std::remove(vecOfValues.begin(), vecOfValues.end(), 0), vecOfValues.end());
return vecOfValues.size();
}
