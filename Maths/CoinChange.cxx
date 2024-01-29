/* Coin change - Recursive naive approach.
Time complexity: O(2^n); where n is the target sum.*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fast_io ios::sync_with_stdio(false);

vector<int> coins;
const int inf = 1e9+7;

int solve(int n) {
   if(n < 0) {
      return inf;
   }
   if(n==0) {
      return 0;
   }
   int best = inf;
   for(auto c : coins) {
      best = min(best,solve(n-c)+1);
   }
   return best;
}

int main(int argc, char **argv) {
   fast_io;
   cin.tie(0);
   int x; cin >> x; // x number of coins
   int c;
   for(int i = 0; i < x; ++i) {
      cin >> c;
      coins.push_back(c);
   }
   int n; cin >> n; // n target sum
   cout << solve(n);
   return 0;
}

