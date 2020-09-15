/* Repeat Number more than N/3 times (N is the size of the array) 

O(N) time complexity */

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1,3,2,1,1};
    unordered_map<int,int> hash;
    for(auto &x : arr)
        hash[x]++;
    for(auto &y : hash){
        if(y.second > (int)arr.size()/3)
            cout << y.first << " ";
    }
    cout << endl;
    return 0;
}