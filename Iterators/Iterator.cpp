// This function takes in a vector of ints and returns only positive values.

#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using std::vector;
vector<int> get_positives(vector<int>::iterator begin, 
                           vector<int>::iterator end) {
vector<int>temp={};
    for(vector<int>::iterator i=begin;i<end;i++)
    {
        if(*i>0)
        temp.push_back(*i);
    }
    return temp;
}

//https://stackoverflow.com/questions/23100583/vectorintiterator-starts-at-end-of-vector-when-set-with-begin
// https://stackoverflow.com/questions/20244743/pass-iterator-as-a-function-parameter
