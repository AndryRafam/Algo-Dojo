// Codechef problem: https://www.codechef.com/problems/ABSTRING

/* 
1) If the length of the string is Odd, then we don't have a solution.
2) If the total number of each character is Odd, then we don't have a solution.
3) If the total number of each character is Even, then we have a solution.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static bool seq_exist(string s){
        if(s.length()&1)
            return false;
        
        unordered_map<char,int> hash; // hashmap to count the number of occurence of each character

        for(auto c : s)
            hash[c]++;
        
        for(auto x : hash){
            if(x.second&1)
                return false;
        }
        return true;
    }
};

int main(){
    int t; // number of test case
    string s;

    cin >> t;

    for(auto i(0); i < t; ++i){
        cin >> s;
        transform(s.begin(),s.end(),s.begin(), ::tolower); // omit case sensitivity
        string res;
        res = (Solution::seq_exist(s)==true) ? "YES":"NO";
        cout << res << "\n";
    }
    return 0;
}