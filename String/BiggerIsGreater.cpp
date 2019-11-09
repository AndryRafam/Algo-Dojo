// Find the next lexicographically greater string of a given one - O(N) time complexity (N length of the string)

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static void biggerisGreater (string &s){
        bool val = next_permutation(s.begin(),s.end());
        if(val==false)
            cout << "No answer\n";
        else
            cout << s << "\n";
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    string test;
    for(auto i = 0; i < T; ++i){
        cin >> test;
        Solution::biggerisGreater(test);
    }
    return 0;
}
