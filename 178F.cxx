/* AtCoder178 f */

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static bool NotSame(vector<int> A, vector<int> B){
		for(auto i = 0; A[i]&&B[i]; i++){
			if(A[i]==B[i])
				return false;
		}
		return true;
	}
	static bool is_possible(vector<int> A, vector<int> B){
		do{
			if(NotSame(A,B)){
				return true;
			}
		}while(next_permutation(B.begin(),B.end()));
		
		return false;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	vector<int> A = {1,1,2,3};
	vector<int> B = {1,2,3,3};
	if(Solution::is_possible(A,B))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
