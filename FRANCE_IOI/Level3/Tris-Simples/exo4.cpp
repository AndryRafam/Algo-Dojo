#include <iostream>
#include <algorithm>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int N; cin >> N;
   int poids[N];
   for(int i = 0; i < N; ++i) {
      cin >> poids[i];
   }
   sort(poids,poids+N);
   for(auto c : poids) {
      cout << c << " ";
   }
   return 0;
}