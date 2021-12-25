//This function sort a list of whitespace separated integers using selection, insertion, and bubble sort WITHOUT the STL library!

#include <vector>
#include <iostream>
using std::vector, std::cout, std::swap,std::endl;
void selection_swap(vector<int> v){
    for (unsigned int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    for (unsigned int i = 0; i < v.size(); i++)
    {
        unsigned int min_idx = i;
        for (unsigned int j = i+1; j < v.size(); j++)
            if (v[j] < v[min_idx])
                min_idx = j;
        if (min_idx!=i){
            swap(v[min_idx], v[i]);
            for (unsigned int k = 0; k < v.size(); k++){
                cout<<v[k]<<" ";
            }  
            cout<<endl;
         }


    }

}

void bubble_swap(vector<int> v){
for (unsigned int k = 0; k < v.size(); k++){
            cout<<v[k]<<" ";
            }
            cout<<endl;
    for (unsigned int  i  = 0; i < v.size(); i++)    

    for (unsigned int  j = 0; j < v.size()-i-1; j++)
        if (v[j] > v[j+1]){
            swap(v[j], v[j+1]);
            for (unsigned int  k = 0; k < v.size(); k++){
            cout<<v[k]<<" ";
            }
            cout<<endl;
    }
}

void insertion_swap(vector<int> v)
{
    for (unsigned int  k = 0; k < v.size(); k++){
            cout<<v[k]<<" ";
            }
 for (unsigned int  i = 1; i < v.size(); i++)
    {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key)
        {
            swap(v[j+1],v[j]);
            for (unsigned int  k = 0; k < v.size(); k++){
            cout<<v[k]<<" ";
            }
            cout<<endl;
            j = j - 1;

        }
    v[j + 1] = key;
        
        
    }

}





int main(){
vector<int> temp1;
int x;
while (std::cin >> x)
{
    temp1.push_back(x);
}
    cout << "Selection Sort\n";
    selection_swap(temp1);
    cout << "Insertion Sort\n";
    insertion_swap(temp1);
    cout << "Bubble Sort\n";
    bubble_swap(temp1);


    return 0;
}
// https://www.geeksforgeeks.org/selection-sort/
//https://www.geeksforgeeks.org/bubble-sort/
//https://www.geeksforgeeks.org/insertion-sort/
// https://stackoverflow.com/questions/5738882/read-input-separated-by-whitespaces-or-newline

