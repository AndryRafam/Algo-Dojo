/*
Calculate the total number of ways to produce a sum amount using the coins.

Time complexity: O(C*N); where C is the number of coins and N the amount.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> coins;
int MOD = 1e9+7;

class Solution{
    public:
    static int solve(int amount){
        vector<int> count(amount+1);
        count[0] = 1;
        for(auto i(1); i <= amount; ++i){
            for(auto &coin : coins){
                if(i-coin >= 0){
                    count[i] += count[i-coin];
                    count[i] %= MOD;
                }
            }
        }
        return count[amount];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    coins = {1,2,5};
    int amount = 11;
    cout << Solution::solve(amount) << endl; // 218
    return 0;
}