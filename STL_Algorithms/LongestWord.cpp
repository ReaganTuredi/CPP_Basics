//This function takes in words via stdin, and outputs the words ordered by length. If two words have the same length, they are output in dictionary order.

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
int main()
{
  std::vector<std::string> word_list;
    std::string str;
        while (std::cin >> str) {
                  word_list.push_back(str);
                              } 

//std::vector<std::string> s={};
sort(word_list.begin(), word_list.end());


auto it = std::unique(word_list.begin(), word_list.end());
word_list.resize(std::distance(word_list.begin(), it));



//word_list.erase(it, word_list.end());

std::sort(word_list.begin(), word_list.end(), []
    (const std::string& first, const std::string& second){
        return first.size() < second.size();
    });

for (int i=0;i<word_list.size();i++){
  std::cout<<word_list[i]<<std::endl;
}

    return 0;
}

// https://www.includehelp.com/cpp-programs/sort-names-in-an-alphabetical-order
// https://stackoverflow.com/questions/20634743/remove-duplicate-strings-in-string-vector
//https://stackoverflow.com/questions/18831470/sorting-a-string-vector-based-on-the-string-size
