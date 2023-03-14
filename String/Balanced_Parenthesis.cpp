#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static bool balanced(string str){
		stack<char> s;
		char ch;
		for(auto x : str){
			if(x =='(' || x == '{' || x =='['){
				s.push(x);
				continue;
			}
			if(s.empty())
				return true;
			switch (x){
				case ')':
					ch = s.top();
					s.pop();
					if(ch == '{' || ch == '[')
						return false;
						break;
				case ']':
					ch = s.top();
					s.pop();
					if(ch == '(' || ch == '{')
						return false;
						break;
				case '}':
					ch = s.top();
					s.pop();
					if(ch == '(' || ch == '[')
						return false;
						break;
			}
		}
		return (s.empty());
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	string test1 = "()[]{}";
	string test2 = "([)]";
	string test3 = " ";
	cout << Solution::balanced(test1) << endl;
	cout << Solution::balanced(test2) << endl;
	cout << Solution::balanced(test3);
}
