/* Check if one string is a permutation of the other one */

#include <bits/stdc++.h>
using namespace std;

class Permut {
	public:
		bool check_permut (string S1, string S2) {
			if (S1.length() != S2.length())
				return -1;
			else {
				sort (S1.begin(),S1.end());
				sort (S2.begin(),S2.end());
			}
			if (S1 == S2)
				return true;
			else
				return false;
		}
};

int main() {
	Permut P;
	string str1, str2;
	getline(cin,str1); cin.ignore();
	getline(cin,str2);
	
	if(P.check_permut(str1,str2))
		cout << "True" << endl;
	else
		cout << "False" << endl;
	return 0;
}
	
	
