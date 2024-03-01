#include <bits/stdc++.h>
using namespace std;

int loveNumber(const string& name){
    int sum = 0;
    for (char c : name){
        int letterVal = c - 'A';
        sum += letterVal;
    }
    while (sum >= 10){
        int newSum = 0;
        while (sum != 0) {
            newSum += sum % 10;
            sum /= 10;
        }
        sum = newSum;
    }
    return sum;
}

int main() {
    string name1, name2;
    cin >> name1 >> name2;
    int loveNum1 = loveNumber(name1);
    int loveNum2 = loveNumber(name2);
    cout << loveNum1 << " " << loveNum2;
    return 0;
}