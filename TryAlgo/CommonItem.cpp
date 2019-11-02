// Common Item: TryAlgo Problems - O(max(NlogN,MlogM)) complexity.
// M = size of first array
// N = size of second array

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static void common_item(vector<int> &arr1, vector<int> &arr2){
        set<int> s;
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        for(auto &i : arr1)
            if(binary_search(arr2.begin(),arr2.end(),i))
                s.insert(i);
        for(auto &x : s)
            cout << x << " ";
    }
};
int main(){
    vector<int> arr1 = {3,6,5,3,9,2};
    vector<int> arr2 = {3,5,3,2,4};
    Solution::common_item(arr1,arr2); // 2 3 5
}
