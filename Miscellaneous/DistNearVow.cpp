/*
Write a function that takes in a string and for each character
returns the distance to the nearest vowel in the string.
If the character is a vowel itself, return 0.

Notes:
    All input strings will contain at least one vowel.
    Strings will be lowercased.
    Vowels are: a, e, i, o, u.

Time complexity: O(N); where N is the length of the input string.
*/

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define fastio ios::sync_with_stdio(false)

vector<int> distToNearVow(const string s) {
    unordered_set<char> vowel = {'a','e','i','o','u'};
    int n = s.size();
    vector<int> ans(n,INT_MAX);
    int vidx = -n;
    for(int i = 0; i < n; ++i) {
        if(vowel.find(s[i])!=vowel.end()) {
            vidx = i;
        }
        ans[i] = min(ans[i],abs(i-vidx));
    }
    for(int i = vidx-1; i >= 0; --i) {
        if(vowel.find(s[i])!=vowel.end()) {
            vidx = i;
        }
        ans[i] = min(ans[i],abs(i-vidx));
    }
    return ans;
}

int main() {
    fastio;
    cin.tie(0);
    string s; cin >> s;
    vector<int> res = distToNearVow(s);
    for(int x : res) {
        cout << x << " ";
    }
    return 0;
}