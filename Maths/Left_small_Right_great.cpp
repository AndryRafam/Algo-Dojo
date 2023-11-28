/*
Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller 
and all right elements to it are greater than it.
Note: Left and right side elements can be equal to required element. 
And extreme elements cannot be required element.
*/

#include <bits/stdc++.h>
using namespace std;

int findElement(vector<int> arr){
    int n = arr.size();
    vector<int> maxLeft(n);
    vector<int> minRight(n);
    // initialize maxleft
    maxLeft[0]=arr[0];
    for(auto i = 1; i < n; ++i){
        maxLeft[i]=max(maxLeft[i-1],arr[i-1]);
    }
    // initialize minRight
    minRight[n-1]=arr[n-1];
    for(auto i = n-2; i >=0; --i){
        minRight[i]=min(minRight[i+1],arr[i+1]);
    }
    // check for the element if it exist
    for(auto i = 1; i <n-1; ++i){
        if(arr[i]>=maxLeft[i]&&arr[i]<=minRight[i]){
            return arr[i];
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    vector<int> arr = {4, 2, 5, 7};
    cout << findElement(arr) << "\n";
    return 0;
}
