#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int subarraySum(vector<int> &arr, int k){
        int count = 0;
        for(auto i = 0; arr[i]; ++i){
            if(arr[i]==k)
                count++;
            int sum = arr[i];
            for(auto j = i+1; arr[j]; ++j){
                sum = sum+arr[j];
                if(sum==k)
                    count++;
            }
        }
        return count;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    vector<int> arr = {1,1,1};
    int k = 2;
    cout << Solution::subarraySum(arr,k);
}
