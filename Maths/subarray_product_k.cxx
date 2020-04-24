#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int answer(vector<int> &nums, int k){
        int count = 0;
        for(auto i = 0; nums[i]; ++i){
            if(nums[i]<k)
                ++count;
            int prod = nums[i];
            for(auto j = i+1; nums[j]; ++j){
                prod = prod*nums[j];
                if(prod<k)
                    ++count;
            }
        }
        return count;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    vector<int> arr = {10, 5, 2, 6};
    int k = 100;
    cout << Solution::answer(arr,k);
}
