/*
Given an array of distinct integers. 
The task is to count all the triplets such that sum of two elements equals the third element.
*/

#include <bits/stdc++.h>
using namespace std;

int triplets(vector<int> arr){
    int count = 0;
    unordered_set<int> s;
    for(auto x : arr){
        s.insert(x);
    }
    for(auto i = 0; i < arr.size(); ++i){
        for(auto j = i+1; j < arr.size(); ++j){
            int c = arr[i]+arr[j];
            if(s.find(c)!=s.end()){
                count++;
            }
        }
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    vector<int> arr = {1, 5, 3, 2};
    cout << triplets(arr) << "\n";
    return 0;
}
