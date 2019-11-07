// Complexity: O(m*n) m = s1.size(); n = s2.size()

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static bool isHidden(string &s1, string &s2){
		for(int i = 0; i < s1.size(); ++i){
			if(find(s2.begin(),s2.end(),s1[i])==s2.end())
				return false;
		}
		return true;
	}
};
int main(){
	ios_base::sync_with_stdio(false);
	string test = "jg heca pixphl syt fo eryzqdd";
	string input;
	for(auto i = 0; i < 5; ++i)
		getline(cin,input);
	printf("%d",Solution::isHidden(test,input));
}
