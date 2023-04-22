//https://cses.fi/problemset/task/1111

#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string &s){
    string s_prime = "";
    for(auto &x : s){
        s_prime += x+string("#");
    }
    s_prime = string("#")+s_prime;
    
    int center = 0;
    int start = 0;
    int end = 0;

    while(center < s_prime.length()){
        int radii = 0;
        int left = center-(radii+1);
        int right = center+(radii+1);
        while(left >= 0 && right < s_prime.length() && s_prime[left]==s_prime[right]){
            radii+=1;
            left--;
            right++;
        }
        if(radii > end-start){
            start = (center-radii) >> 1;
            end = (center+radii) >> 1;
        }
        center++;
    }
    return s.substr(start,end-start);
}

int main(){
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    cout << longestPalindrome(s) << endl;
    return 0;
}