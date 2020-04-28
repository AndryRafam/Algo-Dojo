/* AtCoder Beginner Contest 148 (Task B) */


#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static string str(string &s1, string &s2){
        string res = "";
        for (auto i = 0; s1[i]&&s2[i]; ++i){
            res += s1[i];
            res += s2[i];
        }
        return res;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    string s1 = "ip";
    string s2 = "cc";
    cout << Solution::str(s1,s2); // icpc
}
