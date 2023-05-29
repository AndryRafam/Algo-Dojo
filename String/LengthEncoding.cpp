/*
Giving a string s, rewrite s such that each character of s is followed by its number of frequency.

For example: aabbbcaad -> a2b3c1a2d1.

Time complexity: O(N), where N is the size of s.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static void encode(const string str){
        int count = 1;
        for(auto i(0); i < str.length(); ++i){
            if(str[i]==str[i+1]){
                count++;
            }
            else{
                cout << str[i] << count;
                count = 1;
            }
        }
        return;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s; cin >> s;
    Solution::encode(s);
    return 0;
}