/*
 * Given an integer g >= 2, an integer m > 2 and an integer n >= m;
 * return the first pair of prime numbers between m and n, that has a gap of size g.
 * If there is no such prime numbers, return null.
 *
 * Brute force approach
 * 
 * Time complexity: O((N-M)²)*O(Ksqrt(K)) = O((N-M)²Ksqrt(K))
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
	private:
	static bool isPrime(int x){
		if(x==0 || x==1){
			return false;
		}
		for(auto p(2); p <= sqrt(x); ++p){
			if(x%p==0){
				return false;
			}
		}
		return true;
	}
	public:
	static vector<pair<int,int>> gap (int g, int m, int n){
		vector<pair<int,int>> res;
		for(auto i(m); i < n; ++i){
			for(auto j(i+1); j < n; ++j){
				if(isPrime(i) && isPrime(j) && j-i==g){
					res.emplace_back(i,j);
					return res;
				}
			}
		}
		return {{0,0}};
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	int g,m,n;
	cin >> g >> m >> n;
	for(auto &x : Solution::gap(g,m,n)){
		cout << x.first << " " << x.second << "\n";
	}
	return 0;
}
