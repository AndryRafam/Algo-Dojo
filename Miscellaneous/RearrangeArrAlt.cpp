#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false)

void rearrange(vector<int> arr) {
    auto left = arr.begin();
    auto right = arr.end()-1;
    while(left < right) {
        cout << *right << " " << *left << " ";
        left++;
        right--;
    }
}

int main() {
    fast_io;
    vector<int> arr = {10,20,30,40,50,60,70,80,90,100,110};
    rearrange(arr);
    return 0;
}