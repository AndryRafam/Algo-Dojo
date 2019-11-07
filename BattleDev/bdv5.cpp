#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int signal_len(string n){
        vector<int> temp;
        unordered_map<char,int> hash;
        for(auto &i : n)
            hash[i]++;
        for(auto &x : hash)
            temp.emplace_back(x.second);
        int first = temp[0];
        for(auto x = 1; x < temp.size(); ++x)
            if(temp[x]!=first)
                return n.length();
        return temp.size();
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    string test = "4564564564567";
    cout << Solution::signal_len(test);
}
