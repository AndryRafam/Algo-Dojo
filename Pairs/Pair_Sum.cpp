/*Given two unsorted arrays of size N and M, find all pairs whose sum is a given number

Time Complexity: O(N*M)
Space Complexity: O(1)*/

#include <bits/stdc++.h>
using namespace std;

class Answer{
    public:
    static void find_pairs(vector<int> tab1, vector<int> tab2, int sum){
        vector<int>::iterator it;
        for (auto x : tab1){
            it = find(tab2.begin(),tab2.end(),sum-x);
            if(it!=tab2.end())
                cout << x << " " << sum-x << endl;
        }
    }
};

int main(){
    vector<int> arr1 = {1, 2, 3, 7, 5, 4, 8};
    vector<int> arr2 = {0, 7, 4, 3, 2, 1 };
    Answer::find_pairs(arr1,arr2,8); // (1,7) (7,1) (5,3) (4,4) (8,0)
}
