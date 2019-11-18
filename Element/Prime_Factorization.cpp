// Prime Factorization

#include <bits/stdc++.h>
using namespace std;

vector<int> prime_decomposition(long long int n){
	vector<int> f;
	auto x = 2;
	while(x <= sqrt(n)){
		while(n%x==0){
			f.emplace_back(x);
			n /= x;
		}
		x++;
	}
	if(n > 1)
		f.emplace_back(n);
	return f;
}
int main(){
	ios_base::sync_with_stdio(false);
	long long int n = 123456789123456789; // 3 3 7 11 13 19 3607 3803 52579 
	for(auto &i : prime_decomposition(n))
		cout << i << " ";
	return 0;
}
