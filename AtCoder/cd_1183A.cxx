// CodeForce Problem 1183A

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static bool is_interesting(int n){
		int m,sum = 0;
		while(n > 0){
			m = n%10;
			sum = sum+m;
			n=n/10;
		}
		return(sum%4==0 ? true:false);
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	while(!Solution::is_interesting(n)){
		n++;
	}
	cout << n;
	return 0;
}
