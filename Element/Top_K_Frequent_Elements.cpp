/* Top K_frequent_elements */

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        static void k_elements(vector<int> &nums, int k){
            unordered_map<int,int> hash;
            for(auto i = 0; i < nums.size(); i++)
                hash[nums[i]]++;
            for(auto &x : hash){
                if(x.second >= k)
                    cout << x.first << " ";
            }
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    int k; cin >> k;
    vector<int> tab = {1,1,2,1,2,3};
    Solution::k_elements(tab,k);
}
