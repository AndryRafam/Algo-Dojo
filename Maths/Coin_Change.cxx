/*
Given an integer array coins representing coins of different denominations and an integer amount representing
a total amount of money, you need to determine the fewest number of coins needed to make up that amount. 
If it is not possible to make up that amount using the given coins, return -1.

Time complexity: O(C*N); where C is the number of coins and N is the amount.
*/

#include <bits/stdc++.h>
using namespace std;

int INF = numeric_limits<int>::max();
vector<int> coins;

// Iterative approach
class Solution1{
   public: 
   static int coinChange(int amount){
      vector<int> dp(amount+1,INF);
      dp[0] = 0;
      for(auto &coin : coins){
         for(auto i(coin); i <= amount; ++i){
            dp[i] = min(dp[i],dp[i-coin]+1);
         }
      }
      return dp[amount] <= amount ? dp[amount]:-1;
   }
};

// Iterative approach 2nd version
class Solution2{
   public:
   static int coinChange(int amount){
      vector<int> value(amount+1,INF);
      value[0] = 0;
      for(auto x(1); x <= amount; ++x){
         value[x] = INF;
         for(auto &coin : coins){
            if(x-coin >= 0){
               value[x] = min(value[x],value[x-coin]+1);
            }
         }
      }
      return value[amount] <= amount ? value[amount]:-1;
   }
};

int main(){
   ios_base::sync_with_stdio(false);
   coins = {1,2,5};
   int amount = 11;
   cout << Solution1::coinChange(amount) << endl; // 3 -> 11=5+5+1
   cout << Solution2::coinChange(amount) << endl; // 3 -> 11=5+5+1
   return 0;
}
