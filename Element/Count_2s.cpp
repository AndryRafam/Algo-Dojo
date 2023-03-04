/* Count 2s. Given an integer n, count the number of 2s that appear in all the number from 0 to n (inclusive)
From Gayle Laakmann Mcdowell - Cracking the coding interview, 6th edition.
Brute Force approach.*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int count_two (string s){
        int count = 0;
        for(auto &x : s){
            if(int(x)==50) // Ascii value of 2
                count++;
        }
        return count;
    }
};

int main(){
    int n;
    cin >> n;
    string s = "";
    for(auto i(0); i <= n; i++){
        s+=to_string(i);
    }
    cout << Solution::count_two(s) << endl;
    return 0;
}