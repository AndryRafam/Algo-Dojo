/* Repeat and Missing element in array

 O(N) time complexity O(N) extra space */

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<long long> arr = {3,1,2,5,3}; // 3 4
    vector<long long> arr2; 
    int twice;
    unordered_map<long long,int> hash;
    for(auto &x : arr)
        hash[x]++;
    for(auto &it : hash){
        if(it.second > 1)
            twice = it.first;
    }
    for(auto i = 1; i <= (int)arr.size(); i++)
        arr2.emplace_back(i);
    int sum1 = arr2.size()*(arr2.size()+1)/2;
    int sum2 = 0;
    for(auto &y : arr){
        sum2+=y;
    }
    int miss = sum1 - (sum2-twice);
    cout << twice << " " << miss << endl;
    return 0;
}