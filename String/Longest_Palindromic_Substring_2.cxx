/*Longest palindromic substring.

Given a string s, return the longest palindromic substring in s.

We are gonna solve this problem by expanding around the center of the string.

Time complexity: O(N²), where N is the length of the string.*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    static string longestPalindrome(string s) {
        string temp = "";
        for(auto x : s) {
            temp+=x+string("#");
        }
        string s_prime = string("#")+temp; // for example: aba -> #a#b#a#
        //vector<int> pal_radius(s_prime.length(),0);
        int start = 0;
        int end = 0;
        int center = 0;
        while(center < s_prime.length()) {
            int radius = 0;
            while(center-(radius+1) >=0 && center+(radius+1) < s_prime.length() && s_prime[center-(radius+1)]==s_prime[center+(radius+1)]) {
                radius++;
            }
            //pal_radius[center] = radius;
            
            if(radius > end-start) {
                start = (center-radius)/2;
                end = (center+radius)/2;
            }
            center++;
        }
        return s.substr(start,end-start);
    }
};

int main() {
	string s;
	cin >> s;
	cout << Solution::longestPalindrome(s);
	return 0;
}

