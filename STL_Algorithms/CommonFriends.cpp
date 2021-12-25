// Given two sets of strings containing the names of people, this function returns which name appears in both sets. 

#include <set>
#include <string>
#include <regex>
#include <fstream>
#include <iostream>


std::set<std::string> FriendsInCommon (const std::set<std::string> &s1,const std::set<std::string> &s2 ){

    std::vector<std::string> s1s2_intsec;
    std::set_intersection(s1.begin(), s1.end(),
                          s2.begin(), s2.end(),
                          std::back_inserter(s1s2_intsec));
 std::set<std::string> together(s1s2_intsec.begin(), s1s2_intsec.end());
 //from https://www.delftstack.com/howto/cpp/cpp-set-intersection/
 return together;
}
