/*
Two Strings problem: Given two strings, determine if they share a common substring. Return "YES" or "NO".
A substring may be as small as one character.

Time complexity: O(min(M,N)), where M is the length of the first string and N is the length of
the second string. 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
   public:
   static string twoStrings(string &s1, string &s2){
      unordered_set<char> check_s1(s1.begin(),s1.end());
      for(auto &c : s2){
         if(check_s1.count(c)){
            return "YES";
         }
      }
      return "NO";
   }
};

int main(){
   ios_base::sync_with_stdio(false);
   string s1 = "hello";
   string s2 = "world";
   cout << Solution::twoStrings(s1,s2) << "\n";
   return 0;
}