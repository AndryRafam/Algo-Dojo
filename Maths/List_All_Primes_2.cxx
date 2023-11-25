/*
 * Write a program that takes an integer argument and returns all prime numbers between 1 and the integer (included).
 * 
 * Sieve of eratosthenes approach.
 * 
 * Time complexity: O(Nlog(logN))
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> allprimes(int n){
	vector<int> primes;
	vector<bool> is_prime(n+1,true);
	is_prime[0] = is_prime[1] = false;
	for(size_t p = 2; p<=n; p++){
		if(is_prime[p]){
			primes.emplace_back(p);
		}
		for(size_t j = p; j<=n; j+=p){
			is_prime[j] = false;
		}
	}
	return primes;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	scanf("%d",&n);
	for(size_t x:allprimes(n)){
		cout << x << " ";
	}
	return 0;
}
