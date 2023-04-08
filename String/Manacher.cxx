/* Manacher algorithm: Find the longest palindromic substring in linear time complexity.
 * 
 * Time complexity: O(N), where N is the length of the string.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	static string manacher(string s){
		string s_process = "";
		for(auto &x: s){
			s_process += x + string("#");
		}
		s_process = string("#")+s_process;
		
		vector<int> pal_radius(s_process.length(),0);
		int center = 0;
		int right = 0;
		int max_len = 0; // length of the longest palindrome found so far
		int max_len_center = 0; // center of longest palindrome found so far
		
		for (auto i(0); i < s_process.length(); ++i){
			// Find the corresponding palindrome radius for the current position
			if(i < right){
				int mirror = 2*center - i;
				pal_radius[i] = min(right - i,pal_radius[mirror]);
			}
			
			// expand around the current position
			int left = i - (1 + pal_radius[i]);
			int right = i + (1 + pal_radius[i]);
			
			while(left >= 0 && right < s_process.length() && s_process[left]==s_process[right]){
				pal_radius[i]++;
				left--;
				right++;
			}
			
			// update the center and the right boundary if necessary
			if(i+pal_radius[i] > right){
				center = i;
				right = i+pal_radius[i];
			}
			
			// update the maximum length of the palidrome and its center position
			if(pal_radius[i] > max_len){
				max_len = pal_radius[i];
				max_len_center = i;
			}
		}
		
		// extract the longest palindromic substring
		int start = (max_len_center - max_len) >> 1;
		int end = start + max_len;
		
		string res = s.substr(start,end-start);
		
		return res;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	cout << Solution::manacher(s) << endl;
	return 0;
}
