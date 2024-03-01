#include <iostream>
#include <vector>
using namespace std;

int main() {
    int P;
    cin >> P;
    vector<int> products(P);
    for(int i = 0; i < P; i++) {
        cin >> products[i];
    }
    int O;
    cin >> O;
    for(int i = 0; i < O; i++) {
        int productType, quantity;
        cin >> productType >> quantity;
        products[productType - 1] += quantity;
    }
    for(int i = 0; i < P; i++) {
        cout << products[i] << " ";
    }
    cout << endl;
    return 0;
}
