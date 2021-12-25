//This program  reads in a series of lines with whitespace delimited words and prints the words of each line with separating commas in AP style.

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
int main()
{
    std::string str;
        while(getline(std::cin,str)){
                std::stringstream temp(str);
                std::vector<std::string>word_list;
                std::string word;
                                while(temp>>word){
                  word_list.push_back(word);
                                }
            if(word_list.size()>2){
        for(unsigned int i=0;i<=word_list.size()-3;i++){
            std::cout<<word_list[i]<<", ";
        }
        std::cout<<word_list[word_list.size()-2]<<" and "<<word_list[word_list.size()-1]<<std::endl;
      }
     else if (word_list.size()==2)
            std::cout<<word_list[0]<<" and "<<word_list[1]<<std::endl;
     else
        std::cout<<word_list[0]<<std::endl;
     
        
        
    }
}


// using : https://tutorialsinhand.com/Articles/cpp-program-to-take-input-in-string-format-with-whitespaces.aspx
