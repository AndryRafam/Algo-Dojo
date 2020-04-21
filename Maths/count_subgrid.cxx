/* Count the number of subgrid in nxn array ~O(n³) complexity
 * 
 * Source: Competitive Programmer’s Handbook (Antti Laaksonen) */

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static int count_subgrid(vector<vector<int>> tab){
		int subgrids = 0;
		int n = tab.size();
		for(auto x = 0; x < n; x++){
			for(auto y = x+1; y < n; y++){ // loop over all pairs of (x,y) of rows
				int count = 0;
				for(auto  i = 0; i < n; i++){ // loop over all columns
					if((tab[x][i]==1)&(tab[y][i]==1))
						++count;
				}
				subgrids += ((count-1)*count)/2;
			}
		}return subgrids;
	}
};
int main(){
	ios_base::sync_with_stdio(0);
	vector<vector<int>> test = {{0,1,0,0,1},
								{0,1,1,0,0},
								{1,0,0,0,0},
								{0,1,1,0,1},
								{0,0,0,0,0}};
	cout << Solution::count_subgrid(test); // 2
}
