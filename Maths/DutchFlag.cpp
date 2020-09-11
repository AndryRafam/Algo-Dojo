/* Dutch National Flag problem 0,1,2 colors.

O(N) time complexity; O(1) space complexity */

#include <bits/stdc++.h>
using namespace std;

void sort_vec(vector<int> arr){
    int lo = 0;
    int mid = 0;
    int hi = arr.size()-1;
    while(mid <= hi){
        switch(arr[mid]){
            case 0:
                swap(arr[lo++],arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid],arr[hi--]);
                break;
        }
    }
    for(auto &x : arr)
        cout << x << " ";
    cout << endl;
    return;
}

int main(){
    vector<int> arr = {0,1,1,0,1,2,1,2,0,0,0,1};
    sort_vec(arr);
    return 0;
}