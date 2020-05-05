// CodeForce Problem 158A

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,k,p,count=0; cin >> n >> k;
	vector<int> arr;
	for(auto i = 0; i < n; i++){
		cin >> p;
		arr.emplace_back(p);
	}
	int j = 0;
	while(arr[j]>=arr[k] && arr[j]>0){
		count++;
		j++;
	}
	cout << count;
	return 0;
}
