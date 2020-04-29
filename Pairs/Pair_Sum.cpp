/*Given two unsorted arrays, find all pairs whose sum is a given number
Complexity: O(N*M)*/

#include <bits/stdc++.h>
using namespace std;

class Answer{
    public:
        static void find_pairs(vector<int> tab1, vector<int> tab2, int sum){
            for(auto i = 0; i < tab1.size(); i++){
                for(auto j = 0; j < tab2.size(); j++){
                    if(tab1[i]+tab2[j]==sum)
                        cout << tab1[i] << " " << tab2[j] << endl; 
                }
            }
        }
};

int main(){
    vector<int> arr1 = {1, 2, 3, 7, 5, 4, 8};
    vector<int> arr2 = {0, 7, 4, 3, 2, 1 };
    Answer::find_pairs(arr1,arr2,8); // (1,7) (7,1) (5,3) (4,4) (8,0)
}
