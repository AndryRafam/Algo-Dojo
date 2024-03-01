#include <bits/stdc++.h>
using namespace std;

struct Product {
    int quantity;
    int date;
};

int main() {
    int O;
    cin >> O;
    queue<Product> s;
    for (int i = 0; i < O; i++) {
        int quantity, date;
        cin >> quantity >> date;
        if (quantity > 0) {
            for (int j = 0; j < quantity; j++) {
                s.push({1, date});
            }
        } else {
            quantity = -quantity;
            for (int j = 0; j < quantity; j++) {
                s.pop();
            }
        }
    }

    int min_date = 99999999;
    while (!s.empty()) {
        min_date = min(min_date, s.front().date);
        s.pop();
    }
    cout << min_date << "\n";
    return 0;
}
