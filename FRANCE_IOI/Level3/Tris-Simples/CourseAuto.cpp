#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int nbAutomobiles;
    cin >> nbAutomobiles;
    vector<int> start(nbAutomobiles), end(nbAutomobiles);
    for(int i = 0; i < nbAutomobiles; i++) {
        cin >> start[i];
        end[i] = start[i];
    }
    sort(end.begin(), end.end());
    vector<pair<int, int>> overtakes;
    for(int i = 0; i < nbAutomobiles; i++) {
        for(int j = i; j < nbAutomobiles; j++) {
            if(start[j] == end[i]) {
                for(int k = j; k > i; k--) {
                    swap(start[k], start[k-1]);
                    overtakes.push_back(make_pair(start[k], start[k-1]));
                }
                break;
            }
        }
    }
    cout << overtakes.size() << endl;
    for(auto& overtake : overtakes) {
        cout << overtake.first << " " << overtake.second << endl;
    }
    return 0;
}