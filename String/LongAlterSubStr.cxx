// Longest Alternating Substring
// https://edabit.com/challenge/R95FfS8PGtsCLxnKH

#include <bits/stdc++.h>
using namespace std;

bool odd_even(int n){
    return(n&1 ? true:false);
}

bool alter(string s){
    for(auto i = 0; i < s.length()-1; ++i){
        int t1 = s[i]-'0';
        int t2 = s[i+1]-'0';
        if(odd_even(t1)and(odd_even(t2))||(!odd_even(t1)and(!odd_even(t2))))
            return false;
    }
    return true;
}

void longestAlterSubStr(string s){
    string temp = "";
    priority_queue<pair<int,string>>pq;
    for(auto i = 0; s[i]; ++i){
        for(auto j = 2; j <= s.length()-i; ++j){
            temp=s.substr(i,j);
            if(alter(temp))
                pq.push({temp.length(),temp});
        }
    }
    if(!pq.empty()){
        cout << pq.top().second << endl;
        pq.pop();
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    string test = "225424272163254474441338664823";
    longestAlterSubStr(test);
    return 0;
}
