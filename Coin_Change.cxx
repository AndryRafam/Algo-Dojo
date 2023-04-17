/*
Given an integer array coins representing coins of different denominations and an integer amount representing
a total amount of money, you need to determine the fewest number of coins needed to make up that amount. 
If it is not possible to make up that amount using the given coins, return -1.

Time complexity: O(C*N); where C is the number of coins and N is the amount.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
   public: static int coinChange(vector<int> &coins, int amount){
      vector<int> dp(amount+1,INT_MAX);
      dp[0] = 0;
      for(auto &coin : coins){
         for(auto i(coin); i <= amount; ++i){
            dp[i] = min(dp[i],dp[i-coin]+1);
         }
      }
      return dp[amount] <= amount ? dp[amount]:-1;
   }
};

int main(){
   ios_base::sync_with_stdio(false);
   vector<int> coins = {1,2,5};
   int amount = 11;
   cout << Solution::coinChange(coins,amount); // 3 -> 11=5+5+1;
   return 0;
}