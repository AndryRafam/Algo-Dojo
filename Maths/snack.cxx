// AtCoder Beginner Contest 148 (Problem C)

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int lcm(int a, int b){
        return (a*b)/__gcd(a,b);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    int a = 123;
    int b = 456;
    cout << Solution::lcm(a,b); // 18696
}
