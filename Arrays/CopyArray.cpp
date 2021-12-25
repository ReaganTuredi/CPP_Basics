// This function takes two arrays, and copies the first array to the second.

#include <algorithm>
#include <iostream>

template <typename Type, size_t Size, typename Type2, size_t Size2>
void templated_array_copy(Type (&ary)[Size],Type2 (&ary2)[Size2]) {
   if (Size>Size2){
   std::copy(ary,ary+Size2, ary2);
   }
   else if(Size<Size2){
    std::copy(ary,ary+Size, ary2);
   }
   else if(Size==Size2){
      std::copy(ary,ary+Size, ary2);
   }
   
   for (auto element: ary2)
   std::cout<<element;
  }
