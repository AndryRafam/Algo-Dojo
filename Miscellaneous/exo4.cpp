/*
Write two functions:

    1) One to retrieve all unique substrings that start and end with a vowel.
    2 )One to retrieve all unique substrings that start and end with a consonant.

The resulting array should be sorted in lexicographic ascending order (same order as a dictionary).
Examples

getVowelSubstrings("apple") -> ["a", "apple", "e"]

getVowelSubstrings("hmm") -> []

getConsonantSubstrings("aviation") -> ["n", "t", "tion", "v", "viat", "viation"]

getConsonantSubstrings("motor") -> ["m", "mot", "motor", "r", "t", "tor"]

Notes:

    Remember the output array should have unique values.
    The word itself counts as a potential substring.
    Exclude the empty string when outputting the array.
*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
#include <vector>
using namespace std;

#define fastio ios::sync_with_stdio(false)
unordered_set<char> vowel = {'a','e','i','o','u'};


// O(N^3logN) time complexity solution.
vector<string> getVowelSubstrings(string str) {
    set<string> order;
    int n = str.size();
    for(int i = 0; i < n; ++i) {
        string temp = "";
        for(int j = 1; j <= n-i; ++j) {
            temp = str.substr(i,j);
            int l = temp.length();
            if(vowel.find(temp[0])!=vowel.end() && vowel.find(temp[l-1])!=vowel.end()) {
                order.insert(temp);
            }
        }
    }
    vector<string> ans(order.begin(),order.end());
    return ans;
}

vector<string> getConsonantSubstrings(string str) {
    set<string> order;
	int n = str.size();
    for(int i = 0; i < n; ++i) {
        string temp = "";
        for(int j = 1; j <= n-i; ++j) {
            temp = str.substr(i,j);
            int l = temp.length();
            if(vowel.find(temp[0])==vowel.end() && vowel.find(temp[l-1])==vowel.end()) {
                order.insert(temp);
            }
        }
    }
    vector<string> ans(order.begin(),order.end());
    return ans;
}

/* O(N^2logN) time complexity solution.
Using rolling hash to generate substring in constant time.

const int base = 257;
const int mod = 1e9 + 7;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

long long rolling_hash(string s) {
    long long hash_value = 0;
    long long power = 1;
    for (char c : s) {
        hash_value = (hash_value * base + c) % mod;
        power = (power * base) % mod;
    }
    return hash_value;
}

vector<string> getSubstrings(string s, bool vowel) {
    set<long long> hashes;
    set<string> substrings;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if ((vowel && isVowel(s[i])) || (!vowel && !isVowel(s[i]))) {
            string substring;
            for (int j = i; j < n; j++) {
                substring += s[j];
                if ((vowel && isVowel(s[j])) || (!vowel && !isVowel(s[j]))) {
                    long long hash_value = rolling_hash(substring);
                    if (hashes.find(hash_value) == hashes.end()) {
                        hashes.insert(hash_value);
                        substrings.insert(substring);
                    }
                }
            }
        }
    }
    vector<string> result(substrings.begin(), substrings.end());
    return result;
}

vector<string> getVowelSubstrings(string s) {
    return getSubstrings(s, true);
}

vector<string> getConsonantSubstrings(string s) {
    return getSubstrings(s, false);
}
*/

int main() {
    fastio;
    cin.tie(0);
    string str; cin >> str;
    vector<string> res = getVowelSubstrings(str);
    for(auto c : res) {
        cout << c << " ";
    }
    cout << "\n";
    vector<string> sol = getConsonantSubstrings(str);
    for(auto c : sol) {
        cout << c << " ";
    }
    return 0;
}