// This function adds two numbers unless the input, or the result contains a seven, and throws an exception when this occurs. 

#include <vector>
#include <iostream>
#include<string>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <algorithm>

int safe_add(int x,int y){
    

int temp1=x;
int temp2=y;
int temp3=x+y;
std::stringstream ss ;
ss << temp1 ;
std::string s ;
ss >> s;

std::stringstream ss1 ;
ss1 << temp2 ;
std::string s1 ;
ss1 >> s1;

std::stringstream ss2 ;
ss2 << temp3 ;
std::string s2 ;
ss2 >> s2;

int p_count = std::count(s.begin(), s.end(), '7');
int p1_count = std::count(s1.begin(), s1.end(), '7');
int p2_count = std::count(s2.begin(), s2.end(), '7');


if(p_count> 0 )
throw std::runtime_error("can't add because 6+1 appears in it");

if(p1_count> 0 )
throw std::runtime_error("can't add because 6+1 appears in it");

if(p2_count> 0 )
throw std::runtime_error("can't add because 6+1 appears in it");



std::cout<<p_count;

return x+y;
}
