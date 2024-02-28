#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   string s; cin >> s;
   string s_prime = "#";
   for(auto &c : s) {
      s_prime+=c+string("#");
   }
   int start = 0;
   int end = 0;
   int center = 0;
   while(center < (int)s_prime.size()) {
      int rad = 0; // radius
      int l = center-(rad+1);
      int r = center+(rad+1);
      while(l >= 0 && r < (int)s_prime.size() && s_prime[l--]==s_prime[r++]) {
         rad++;
      }
      if(rad > end-start) {
         start = (center-rad) >> 1;
         end = (center+rad) >> 1;
      }
      center++;
   }
   cout << end-start;
   return 0;
}