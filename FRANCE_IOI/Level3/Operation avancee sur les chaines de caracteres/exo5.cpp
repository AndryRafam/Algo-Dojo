#include <bits/stdc++.h>
using namespace std;

int n;
int sum = 0;

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    while(!cin.fail()){
        sum+=n;
        cin >> n;
    }
    cout << sum;
    return 0;
}