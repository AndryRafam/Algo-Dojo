// Count prime numbers
// https://edabit.com/challenge/Ba4vZuzC7b2Zr6SPs

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static bool is_prime(long long n){
		if(n==2)
			return true;
		for(auto i = 2; i <= sqrt(n); ++i){
			if(n%i==0)
				return false;
		}
		return true;
	}
	static int primeNumber(long long n){
		auto count = 0;		
		for(auto x = 2; x <= n; ++x){
			if(is_prime(x))
				count++;
		}
		return count;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	int n = 30;
	cout << Solution::primeNumber(n) << endl;
	return 0;
}
