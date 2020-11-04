// Column with maximum sum
// https://edabit.com/challenge/SEWasMaZyxkuGiY6o

#include <bits/stdc++.h>
using namespace std;

void col(vector<int> arr, int n){
    priority_queue<pair<int,int>> pq;
    int t = arr.size();
    for(auto i(0); i < n; i++){
        int sum = arr[i];
        int j = i;
        while(j < t){
            sum+=arr[j];
            j+=n;
        }
        pq.push({sum,i+1});
    }
    if(!pq.empty()){
        printf("%d\n",pq.top().second);
        pq.pop();
    }
    return;
}

int main(){
    vector<int> arr = {3, 9, 14, 7, 6, 13, 9, 10, 1, 5, 10, 17, 16, 6, 3, 18}; // 4
    int n = 4;
    col(arr,n);
    return 0;
}