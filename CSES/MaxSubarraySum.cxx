#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> &arr){
    int curr_sum = arr[0];
    int max_sum = arr[0];
    for(auto i(1); i < arr.size(); ++i){
        curr_sum = max(arr[i],curr_sum+arr[i]);
        max_sum = max(curr_sum,max_sum);
    }
    return max_sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    vector<int> arr = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    cout << kadane(arr) << endl;
    return 0;
}