// This function takes a vector of vector of ints and returns the sum of all the ints.

#include <iostream>
#include<vector>
#include <string>

int sum(std::vector<std::vector<int>> const &v)
{ 
    int sum=0;
    for(int i=0;i<v.size();++i)
    {
        for(int j=0;j<v[i].size();++j)
        {
            sum=sum+v[i][j];
        }
    }
return sum;
}
//using the bottom portion of https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/
