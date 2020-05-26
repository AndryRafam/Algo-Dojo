/* Special triplet pythagorean: a² + b² = c² 
 * 
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc. */

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

class Solution{
	public:
	static long long fast_pow(long long base, long long exp){ // fast power function
		long long r = 1;
		while(exp > 0){
			if(exp%2==1)
				r = (r*base)%MOD;
			base = (base*base)%MOD;
			exp >>= 1; // bit manipulation equivalent to exp / 2
		}
		return r;
	}
	static bool pythago(long long a, long long b, long long c){
		return (fast_pow(a,2)+fast_pow(b,2)==fast_pow(c,2));
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	for(auto i = 1; i <= 1000; i++){
		long long l = 2; // left pointer
		long long r = 1000; // right pointer
		while(l < r){
			if(i+l+r==1000 && Solution::pythago(i,l,r)){
				cout << i*l*r << endl; // 31875000
				return 0;
			}
			else if(i+l+r < 1000)
				l++;
			else
				r--;
		}
	}
	return 0;
}
