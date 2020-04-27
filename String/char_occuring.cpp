// Occuring number of character within a string - O(N) complexity

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	static int occur(string &s, char c){
		unordered_map<char,int> hash;
		for(auto &x : s)
			hash[x]++;
        for(auto &y : hash)
			if(y.first==c)
				return y.second;
        return 0;
	}
};

int main(){
    ios_base::sync_with_stdio(0);
    string test = "agoraphobia";
    char c = 'a';
    cout << Solution::occur(test,c);
}
