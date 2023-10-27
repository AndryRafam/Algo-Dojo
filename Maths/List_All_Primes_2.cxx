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
	for(int p(2); p<=n; p++){
		if(is_prime[p]){
			primes.emplace_back(p);
		}
		for(int j(p); j<=n; j+=p){
			is_prime[j] = false;
		}
	}
	return primes;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int x:allprimes(n)){
		printf("%d ",x);
	}
	return 0;
}
