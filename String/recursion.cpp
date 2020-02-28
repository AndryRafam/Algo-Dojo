#include <bits/stdc++.h>
using namespace std;

class Answer{
    public:
    static void reverse(string &s, int len){
        cout << s[len];
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s = "test";
    int n = s.size();
    for(auto i = 0; i < n; ++i)
        Answer::reverse(s,n-1-i);
}
