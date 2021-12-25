//This function returns only letters given a string of numbers and letters 

#include<vector>
#include<string>
#include <algorithm>
#include <numeric>
std::vector<int> get_numbers(std::string str){
    std::string temp_string;
    std::vector<std::string> temp_vec;
    std::vector<int> return_values;

    for(int i=0;i<str.size();i++){
        if(isdigit(str[i]) or str[i]=='-'){
            temp_string = temp_string+str[i];
            continue;
        }
        else{
            temp_vec.push_back(temp_string);
        }
            temp_string.erase();
    }
    temp_vec.push_back(temp_string);
    for(int i=0;i<temp_vec.size(); i++){
    return_values.push_back(stoi(temp_vec[i]));
    }
    return return_values;
} 
