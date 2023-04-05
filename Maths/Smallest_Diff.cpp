// Smallest difference between pairs of array - Each from array O(N^2) complexity

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int smallest_diff(vector<int> &arr1, vector<int> &arr2){
        int diff = 0;
        vector<int> temp;
        for(auto i = 0; i < arr1.size(); ++i){
            for(auto j = 1; j < arr2.size(); ++j){
                diff = arr1[i]-arr2[j];
                if(diff >= 0)
                    temp.emplace_back(diff);
            }
        }
        return *min_element(temp.begin(),temp.end());
    }
};
int main(){
    vector<int> test1 = {1,3,15,11,2};
    vector<int> test2 = {23,127,235,19,8};
    printf("%d",Solution::smallest_diff(test1,test2));
}
