/*First single integer*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        static void single(vector<int> &nums){                                                         
            unordered_map<int,int> hash;
            for(auto i = 0; i < nums.size(); i++)
                hash[nums[i]]++;
            for(auto &x : hash){
                if(x.second == 1)
                    cout << x.first;
            }
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    vector<int> v1 = {2,2,1};
    vector<int> v2 = {4,1,2,1,2};
    Solution::single(v1); cout << endl;
    Solution::single(v2);
}
