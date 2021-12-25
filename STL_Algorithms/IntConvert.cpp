// This function takes a vector of strings, and converts each to an int and returns the resulting vector

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
#include <stdexcept>
using std::invalid_argument;


int helper(const string & input) {
  try {
    return std::stoi(input);
  } catch (invalid_argument & e) {
    return 0;
  }
}

vector<int> all_to_int(const vector<string> & strings){
  std::vector<int> s;
  std::transform(strings.begin(), strings.end(), std::back_inserter(s),helper);
