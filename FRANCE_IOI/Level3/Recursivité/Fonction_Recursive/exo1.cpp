#include <bits/stdc++.h>
using namespace std;

string addBrackets(int number, int brackets) {
    if (brackets == 0) {
        return to_string(number);
    } else {
        return "[" + addBrackets(number, brackets - 1) + "]";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int number, brackets;
    cin >> number >> brackets;
    cout << addBrackets(number, brackets) << "\n";
    return 0;
}