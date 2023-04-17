/*
Given an integer array coins representing coins of different denominations and an integer amount representing
a total amount of money, you need to determine the fewest number of coins needed to make up that amount. 
If it is not possible to make up that amount using the given coins, return -1.

Time complexity: O(C*N); where C is the number of coins and N is the amount.
*/

using System;

class Program{
    public static int coinChange(int[] coins, int amount){
        int[] dp = new int[amount+1];
        Array.Fill(dp,amount+1);
        dp[0] = 0;
        foreach(int coin in coins){
            for(int i = coin; i <= amount; ++i){
                dp[i] = Math.Min(dp[i],dp[i-coin]+1);
            }
        }
        return dp[amount] <= amount ? dp[amount]:-1;
    }
    public static int Main(){
        int[] coins = {1,2,5};
        int amount = 11;
        Console.Write(coinChange(coins,amount));
        return 0;
    }
}
