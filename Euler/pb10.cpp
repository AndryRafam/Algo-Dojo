#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static long long erato(long long n){ // eratosthene sieve
		vector<bool> prime(n+1);
		prime.assign(n+1,true);
		for(auto x = 2; x*x <= n; x++){
			if(prime[x]==true){
				for(auto i=x*x; i <= n; i+=x)
					prime[i]=false;
			}
		}
		long long sum = 0;
		for(auto x = 2; x <= n; x++){
			if(prime[x])
				sum+=x;
		}
		return sum;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	long long n = 2000000;
	cout << Solution::erato(n) << endl;
	return 0;
}
