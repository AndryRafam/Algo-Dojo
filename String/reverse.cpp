#include <bits/stdc++.h>
using namespace std;

class Reverse {
	public:
		void reverse_string(string input) {
			for (int i = input.length()-1; i >= 0; i--) {
				if (input[i] != '\0')
					cout << input[i] << " ";
				else
					cout << input[i];
			}
			cout << endl;
		}
};

int main()
{
	Reverse R;
	string str;
	getline(cin,str);
	R.reverse_string(str);
	return 0;
}
