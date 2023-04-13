/*
Find the factorial of a given number n.

Solution_1: Recursive solution, O(n) time complexity and O(n) space complexity.

Solution_2: Dynamic programming, O(n) time complexity and O(n) space complexity.
*/

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

// Recursive solution
class Solution_1{
    public:
    static ull factorial(ull n){
        if(n==0){
            return 1;
        }
        return n*factorial(n-1);
    }
};

// Dynamic programming
class Solution_2{
    public:
    static ull factorial(ull n){
        vector<ull> fact(n+1);
        fact[0] = 1;
        fact[1] = 1;
        for(auto i(2); i <= n; ++i){
            fact[i] = i*fact[i-1];
        }
        return fact[n];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    ull n;
    cin >> n;
    cout << Solution_1::factorial(n) << "\n";
    cout << Solution_2::factorial(n) << "\n";
    return 0;
}
