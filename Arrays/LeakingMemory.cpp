// Here is a program that leaks memory.

#include <vector>
#include <algorithm>
std::string MultipleOf4(std::string input){
std::vector<int> string_to_vector(input.begin(), input.end());  // make string into vector.

std::vector<int> temp_vec;// make new empty vector

copy_if(string_to_vector.begin(), string_to_vector.end()-1, back_inserter(temp_vec), [](int i) { return ((i % 4)==0); });
//copy only things that are a multiple of 4 into temp_vec

std::string result(temp_vec.size(), 0); // create an empty string

std::transform(temp_vec.begin(), temp_vec.end(), result.begin(),
        [](int k) { return static_cast<char>(k); }); // transform ints to chars, and put this in the empty string
        
return result;

}
