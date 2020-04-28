// AtCoder Beginner Contest (Problem 148)

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int double_fact(int n){
        int fact[n+1]; 
        fact[0]=1;
        fact[1]=1;
        for (auto i = 2; i <= n; ++i){
            fact[i]=i*fact[i-2];
        }
        int res = fact[n];
        int count = 0;
        while(res%10==0){
			count++;
			res /= 10;
        }
        return count;
    }

};
int main(){
    ios_base::sync_with_stdio(0);
    int n = 12;
    cout << Solution::double_fact(n); // 1 zero trailing (46080)
}
