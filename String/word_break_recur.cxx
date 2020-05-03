// Word break in O(exp(N)) complexity (Recursion version)

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static bool word_break(string s, vector<string> &dict){
        if(s.size()==0)
            return true;
        for(auto i = 1; i <= s.size(); i++){
			if(find(dict.begin(),dict.end(),s.substr(0,i)) != dict.end() && word_break(s.substr(i),dict))
				return true;
        }
        return false;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	string test = "lintcode";
	vector<string> dict = {"lint","de","co"};
	cout << Solution::word_break(test,dict); // True
}

