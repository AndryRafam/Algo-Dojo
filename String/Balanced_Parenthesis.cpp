/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
*/

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
			}
			else{
				if(s.empty()){
					return true;
				}
				char top = s.top();
				s.pop();
				if((top=='(' && x!=')') || (top=='{' && x!='}') || (top=='[' && x!=']')){
					return false;
				}
			}
			
		}
		return (s.empty());
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	string test1 = "()[]{}";
	string test2 = "([)]";
	string test3 = "{()}[]";
	string test4 = ""; // empty string
	cout << Solution::balanced(test1) << endl; // 1
	cout << Solution::balanced(test2) << endl; // 0
	cout << Solution::balanced(test3) << endl; // 1
	cout << Solution::balanced(test4); // 1
}
