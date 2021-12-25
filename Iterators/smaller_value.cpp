 //This function returns an iterator pointing at the first element that is strictly smaller than the element before it.

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <vector>
std::vector<int>::iterator smaller_than_predecessor(std::vector<int> &vec) {
     std::vector<int>::iterator ptr = vec.begin();
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] < vec[i - 1]) {
             advance(ptr, i);
             return ptr;
        }
        
        //else
            //advance(ptr, vec.size()-1);
           // return ptr;
        
    }
    return  vec.end();
}



//using:  https://appdividend.com/2019/06/15/cpp-iterators-tutorial-with-example-iterators-in-cpp/
