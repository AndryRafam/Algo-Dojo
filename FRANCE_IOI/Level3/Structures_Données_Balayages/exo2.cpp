#include <bits/stdc++.h>
using namespace std;

struct Product{
    int quantity,date;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    stack<Product> piles;
    int O; cin >> O;
    for(int i = 0; i < O; ++i) {
        int quantity,date;
        cin >> quantity >> date;
        if(quantity > 0) {
            for(int j = 0; j < quantity; ++j) {
                piles.push({1,date});
            }
        } else {
            quantity = -quantity;
            for(int j = 0; j < quantity; ++j) {
                piles.pop();
            }
        }
    }
    int min_date = 99999999;
    while(!piles.empty()) {
        min_date = min(min_date,piles.top().date);
        piles.pop();
    }
    cout << min_date << "\n";
    return 0;
}



