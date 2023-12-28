#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int> &arr) {
    unordered_set<int> hashset;
    vector<int> res;
    for(auto &x : arr) {
        if(hashset.find(x)!=hashset.end()) {
            res.push_back(x);
        }
        hashset.insert(x);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    vector<int> test = {1,2,2};
    for(auto &y : findDuplicates(test)) {
        cout << y << " ";
    }
    return 0;
}
