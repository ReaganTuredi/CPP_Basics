// This function returns a vector<string> where each element of the returned vector is the concatentation of the elements in the original vectors

#include <string>
#include <vector>
std::vector<std::string> zip(const std::vector<std::string> &x , const std::vector<std::string> &y)
{
  std::vector<std::string> return_vec;
  if(x.size()==y.size()){
 
  int i;
  for(i = 0; i < x.size(); i++) 
  {
    return_vec.push_back(x.at(i) + y.at(i));
  }
   
}
  else if(x.size()>y.size()){
  int j;
  for(int j = 0; j <y.size(); j++) 
  {
    return_vec.push_back(x.at(j) + y.at(j));
  }
for (int j=y.size(); j<x.size();j++){
  return_vec.push_back(x.at(j));
}
}

  else if(x.size()<y.size()){
   int z;
  for(int z = 0; z < x.size(); z++) 
  {
    return_vec.push_back(x.at(z) + y.at(z));
  }
  for (int z=x.size(); z<y.size();z++){
    return_vec.push_back(y.at(z));
  }
}
return return_vec;
 }
