// Check if one string is a permutation of the other one. Case sensitive. O(N) complexity, N length of the strings

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static bool isPermut(string &s1, string &s2){
        if(s1.length()!=s2.length())
            return false;
        unordered_map<char,int> hash;
        for(auto i = 0; i < s1.length(); ++i){
            hash[s1[i]]++;
            hash[s2[i]]--;
        }
        for(auto &x : hash)
            if(x.second!=0)
                return false;
        return true;
    }
};

int main(){
	string test1 = "akka";
	string test2 = "kaka";
	printf("%d",Solution::isPermut(test1,test2));
}
