// Codechef problem: https://www.codechef.com/problems/NUM239

#include<bits/stdc++.h>
using namespace std;

bool is_pretty(int N){
    int res;
    res = N%10; // etract the last digit
    if(res==2 || res==3 || res==9)
        return true;
    return false;
}

int main(){
    int l, r;
    int count = 0;
    int t; // test case
    cin >> t;
    for (auto j(0); j < t; ++j){
        cin >> l >> r;
        for(auto i(l); i <= r; ++i){
            if(is_pretty(i))
                count++;
        }
        cout << count << "\n";
        count = 0;
    }
    return 0;
}
