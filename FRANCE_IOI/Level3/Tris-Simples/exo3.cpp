#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int N; cin >> N;
   vector<int> polluants(N);
   for(int i = 0; i < N; ++i) {
      cin >> polluants[i];
   }
   sort(polluants.begin(),polluants.end());
   for(auto c : polluants) {
      cout << c << " ";
   }
   return 0;
}