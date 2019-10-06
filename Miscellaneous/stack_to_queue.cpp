/* Implementing queue with two stacks */

#include <bits/stdc++.h>
using namespace std;

main()
{
	stack<int> s1;
	stack<int> s2;
	int temp;

	s1.push(0);
	s1.push(1);
	s1.push(2);

	while (!s1.empty())
	{ temp = s1.top(); cout << " " << s1.top(); s2.push(temp); s1.pop(); }

	cout << endl;
	while (!s2.empty())
	{ cout << " " << s2.top(); s2.pop(); }
	cout << endl;
}
