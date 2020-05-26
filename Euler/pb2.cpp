#include <bits/stdc++.h>
using namespace std;

int fib(int n){
	int dp[n+2];
	dp[0]=0;
	dp[1]=1;
	for(auto i = 2; i <= n; i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	int sum = 0;
	int n = 1;
	while(fib(n) < 4000000){
		if(!(fib(n)&1))
			sum+=fib(n);
		n++;
	}
	cout << sum << endl;
	return 0;
}
