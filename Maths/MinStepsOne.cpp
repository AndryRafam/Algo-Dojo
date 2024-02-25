/*
On a positive integer, you can perform any one of the following 3 steps.
1.) Subtract 1 from it. ( n = n - 1 ).
2.) If its divisible by 2, divide by 2. ( if n % 2 == 0 , then n = n / 2 ).
3.) If its divisible by 3, divide by 3. ( if n % 3 == 0 , then n = n / 3 ).
Now the question is, given a positive integer n, find the minimum number of steps that takes n to 1

Time complexity: Linear, O(n).
*/

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false)

int getMin(int n) {
    int dp[n+1];
    if(n==0) {
        return -1;
    }
    dp[1]=0;
    for(int i = 2; i <= n; ++i) {
        dp[i]=1+dp[i-1];
        if(i%2==0) {
            dp[i]=min(dp[i],1+dp[i/2]);
        }
        if(i%3==0) {
            dp[i]=min(dp[i],1+dp[i/3]);
        }
    }
    return dp[n];
}

int main() {
    fast_io;
    int n; cin >> n;
    cout << getMin(n);
    return 0;
}