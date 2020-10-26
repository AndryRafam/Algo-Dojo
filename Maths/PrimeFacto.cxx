// Prime Factorization of an Integer
// https://edabit.com/challenge/aoccBQ9jvn6bbAvw6

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static vector<int> factors(int n){
		vector<int> fac;
		auto x = 2;
		while(x <= sqrt(n)){
			while(n%x==0){
				fac.emplace_back(x);
				n /= x;
			}
			x++;
		}
		if(n > 1)
			fac.emplace_back(n);
		return fac;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	int n = 8912234;
	for(auto x : Solution::factors(n)) 
		cout << x << " "; [2,47,94811]
	cout << endl;
	return 0;
} 
