#include <bits/stdc++.h>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int i = 0;
   int n; cin >> n;
   int res = 0;
   while(pow(2,i) <= n) {
      res = pow(2,i);
      i++;
   }
   cout << res;
   return 0;
}