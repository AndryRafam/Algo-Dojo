#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<pair<int,string>> arr1;
    vector<pair<int,string>> arr2;

    int N; cin >> N;
    for(int i = 0; i < N; ++i) {
        int nbUnit; cin >> nbUnit;
        cin.ignore();
        string product; cin >> product;
        arr1.emplace_back(nbUnit,product);
    }

    int M; cin >> M;
    for(int j = 0; j < M; ++j) {
        int nbStock; cin >> nbStock;
        cin.ignore();
        string stockProd; cin >> stockProd;
        arr2.emplace_back(nbStock,stockProd);
    }
    
    int sum = 0;
    for(int i = 0; i < (int)arr1.size(); ++i) {
        for(int j = 0; j < (int)arr2.size(); ++j) {
            if(arr1[i].second==arr2[j].second) {
                if(arr1[i].first >= arr2[j].first) {
                    sum+=arr2[j].first;
                }
                else {
                    sum+=arr1[i].first;
                }
            }
        }
    }
    
    cout << "\n" << sum;
    return 0;
}