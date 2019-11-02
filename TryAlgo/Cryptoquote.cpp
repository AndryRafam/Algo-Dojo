// Cryptoquote: TryAlgo Problem - O(N^2) Complexity

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static string decrypt(string &encrypt, string &key){
        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
        vector<pair<char,char>> mapping;
        string result = "";
        for(auto i = 0; i < alphabet.size(); ++i)
            mapping.emplace_back(alphabet[i],key[i]);
        for(auto x = 0; x < encrypt.size(); ++x){
            for(auto &itr : mapping)
                if(encrypt[x]==itr.first)
                    result+=itr.second;
        }
        return result;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    string test = "FDY GAI BG UKMY"; // THE SKY IS BLUE
    string key = "KIMHOTSQYRLCUZPAGWJNBVDXEF ";
    cout << Solution::decrypt(test,key);
}
