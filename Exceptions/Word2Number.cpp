// This function returns a string formed by concatenating the words of the first vector in the order denoted by the second vector.
// It throws an exception for an invalid index.

#include <vector>
#include <iostream>
#include<string>
#include <iostream>

std::string Lookup(const std::vector<std::string> &strings, const std::vector<int> &ints){
std::string temp;
for(int i=0 ;i<ints.size(); i++){
std::cout<<ints[i];
if(ints[i] > strings.size()-1 or ints[i] < 0 )
throw std::out_of_range("out of range");
}

for(int i=0 ;i<ints.size(); i++){
int ints_location= ints[i];
temp= temp +strings[ints_location]+" ";
}
return temp;

}
