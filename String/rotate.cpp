// Rotational point in a dictionnary

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static vector<pair<int,string>> rotation(vector<string> &arr){
        vector<pair<int,string>> rot;
		for(auto i = 0; i < arr.size(); i++){
			if(arr[i+1]>=arr[i])
				continue;
			else{
				rot.emplace_back(i+1,arr[i+1]);
                break;
            }
		}
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
