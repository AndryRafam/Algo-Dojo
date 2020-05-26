#include <bits/stdc++.h>
using namespace std;

bool palindrome(int n){
	int digit,rev = 0;
	int num = n;
	while(n > 0){
		digit = n%10;
		rev = (rev*10)+digit;
		n = n/10;
	}
	return(num==rev);
}

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	int max = 0;
	for(auto a = 100; a <= 999; a++){
		for(auto b = a+1; b <= 999; b++){
			if(max < a*b && palindrome(a*b))
				max = a*b;
		}
	}
	cout << max << endl; // 906609
	return 0;
}
