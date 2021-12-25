// This function takes in two vectors of strings, and returns a vector of strings that are in the second string, but not the first. 

#include <vector>
#include <string>
#include<algorithm>
#include <numeric>   
#include <iostream>
std::vector<std::string> unique_pokemon(const std::vector<std::string>& old_pokedex, 
                              const std::string& found_pokemon){
std::vector<std::string> pokedex (old_pokedex);
std::string sum;
sum = accumulate(pokedex.begin(), pokedex.end()-1, sum);
for(int i=0;i<=found_pokemon.size()-1;i++){
    sum.push_back(found_pokemon[i]);
}
std::unique(sum.begin(), sum.end());
}
