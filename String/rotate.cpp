// Rotational point in a dictionnary -O(N) complexity

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static vector<pair<int,string>> rotation(vector<string> &arr){
        vector<pair<int,string>> rot;
        int i = 0;
        while(arr[i+1]>=arr[i]){
			i++;
		}
		rot.emplace_back(i+1,arr[i+1]);
		return rot;
	}
};

int main(void){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	vector<string> test = {
	"ptolemaic",
    	"retrograde",
    	"supplant",
    	"undulate",
    	"xenoepist",
    	"asymptote",  // <-- rotates here!
    	"babka",
    	"banoffee",
    	"engender",
    	"karpatka",
    	"othellolagkage"};

    for(auto &x : Solution::rotation(test))
        cout << x.second << " → " << x.first;
}
