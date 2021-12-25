// This program copies and array to a vector 

template <typename T>
std::vector<T> ArrayToVector(T *arr, int size){
  //int arr[size];
   std::vector<T> numbers(arr, arr+size);
   //for (int i=0;i<numbers.size();i++){
   //    std::cout<<numbers[i];
  // }
   delete[] arr;
   return numbers;
}
