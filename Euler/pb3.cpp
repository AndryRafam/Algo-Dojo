#include <bits/stdc++.h>
using namespace std;

long long factor(long long n){
	vector<long long> prime;
	for(auto x = 2; x*x <= n; x++){
		while(n%x==0){
			prime.emplace_back(x);
			n/=x;
		}
	}
	if(n > 1)
		prime.emplace_back(n);
	return prime[prime.size()-1];
}

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	long long n = 600851475143; // 6857
	cout << factor(n) << endl;
	return 0;
}

