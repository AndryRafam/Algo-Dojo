/*Palindrome program which check if a string is a palindrome.
  Char case is ignore*/

#include <bits/stdc++.h>
using namespace std;

class Palindrome {
	public:
		bool isPalindrome (string word) {
			transform(word.begin(),word.end(),word.begin(),::tolower);
			int i = 0;
			while (i < word.length()/2 && (word[i] == word[word.length()-1-i])){
				return true;
				i+=1;
			}
		}
};

int main(void)
{
	Palindrome P;
	string input;
	cout << "Enter a string → ";
	getline(cin,input);
	cout << P.isPalindrome(input) << endl;
}
