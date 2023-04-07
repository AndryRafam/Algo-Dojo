/*
Write a program that takes an integer argument and returns all prime numbers between 1 and the integer (included).

Brute force approach

Time complexity: O(N*sqrt(N)).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
	private:
	static bool isPrime(int n){
		if(n== 0 || n==1){
			return false;
		}
		for(auto i(2); i <= sqrt(n); ++i){
			if(n%i==0){
				return false;
			}
		}
		return true;
	}
	public:
	static vector<int> listAllPrimes(int n){
		vector<int> primes;
		for(auto x(0); x <= n; ++x){ 
			if(isPrime(x)){
				primes.emplace_back(x);
			}
		}
		return primes;
	}
};
// driver program
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(auto &k : Solution::listAllPrimes(n)){
		cout << k << " ";
	}
	return 0;
}
