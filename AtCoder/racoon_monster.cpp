#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int h, n, k, count=0;
	vector<int> arr;
	cin >> h >> n;
	for(auto i = 0; i < n; i++){
		cin >> k;
		arr.emplace_back(k);
	}
	sort(arr.begin(),arr.end());
	for(auto &x : arr){
		count++;
		if(h-x <= 0){
			cout << "Yes";
			return 0;
		}
		h = h-x;
	}
	cout << "No";
	return 0;
}
