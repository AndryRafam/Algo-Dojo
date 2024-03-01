/*France IOI - Niveau 3.
Tris Simples: Densité Plus Proche.
*/

#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    multiset<int> densities;
    for(int i = 0; i < N; i++) {
        int density;
        cin >> density;
        densities.insert(density);
    }
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int query;
        cin >> query;
        auto lower = densities.lower_bound(query);
        int minDensity;
        if(lower == densities.end()) {
            minDensity = *prev(lower);
        } else if(lower == densities.begin() || abs(query - *lower) < abs(query - *prev(lower))) {
            minDensity = *lower;
        } else {
            minDensity = *prev(lower);
        }
        cout << minDensity << endl;
    }
    return 0;
}
