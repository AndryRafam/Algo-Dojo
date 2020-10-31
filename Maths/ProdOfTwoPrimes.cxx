// Product of Two Prime Numbers
// https://edabit.com/challenge/LuC3AwFKJg2eEA4Kz

#include <bits/stdc++.h>
using namespace std;

bool f(int n){
	vector<int> s;
	auto x = 2;
	while(x <= sqrt(n)){
		while(n%x==0){
			s.emplace_back(x);
			n/=x;
		}
		x++;
	}
	if(n > 1)
		s.emplace_back(n);
	if(s.size()!=2)
		return false;
	return true;
}

int main(){
	int n = 5767;
	printf("%d\n",f(n)); // True
	return 0;
}	
