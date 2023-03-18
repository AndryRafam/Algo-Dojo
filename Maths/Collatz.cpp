/*
Implementation of Collatz conjecture.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    static void collatz (int n) {
        while(n!=1) {
            cout << n << "->";
            if(n&1) {
                n = 3*n+1;
            }
            else {
                n = n/2;
            }
        }
        cout << n;
    }
};

int main () {
    int n;
    cin >> n;
    Solution::collatz(n);
    return 0;
}