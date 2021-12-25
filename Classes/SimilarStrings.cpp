//This function returns strings that are similar to eachother. The amount of similar letters is determined by the input.

#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iostream>
#pragma once
std::vector<int> getDistances(std::string a, std::string b);

int getDistance(std::string a, std::string b);

class Comparer{
    private:
    int N;

    public:
    Comparer(int N);

    bool operator()(std::string a, std::string b);
};


int CloseEnough(const std::vector<std::string>& words, int N);




#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iostream>
#include "code.h"

std::vector<int> getDistances(std::string a, std::string b){
    // returns vector with non matching characters:
    // abcd
    // abba
    // 0011
    std::vector<int> result;
    // https://en.cppreference.com/w/cpp/algorithm/transform
    std::transform(
        a.begin(),
        a.end(),
        b.begin(),
        std::back_inserter(result),
        [](char a, char b)
        {
            return a != b;
        }
    );
    return result;
}

int getDistance(std::string a, std::string b){
    // sums values in vector from getDistances() function:
    // abcd
    // abba
    // = 2
    std::vector<int> distances = getDistances(a, b);
    // https://en.cppreference.com/w/cpp/algorithm/accumulate
    return std::accumulate(distances.begin(), distances.end(), 0, [](int a, int b){ return a + b; });
}


Comparer::Comparer(int N){
    this->N = N;
}

bool Comparer::operator()(std::string a, std::string b){
    return getDistance(a, b) <= N;
}


int CloseEnough(const std::vector<std::string>& words, int N){
    Comparer c(N);
    // std::adjacent_find finds adjacent values using function (third argument). std::adjacent_find only passes the two values to compare
    // but we need to compare this to  N, which we can not pass as parameter
    // in order to go around this, we create custom function object which stores the value N, and has overloaded call operator so that std::adjacent_find can use it

    // https://en.cppreference.com/w/cpp/algorithm/adjacent_find
    std::vector<std::string>::const_iterator result = std::adjacent_find(words.begin(), words.end(), c);
    if (result == words.end()) return -1;
    return result - words.begin();
}
