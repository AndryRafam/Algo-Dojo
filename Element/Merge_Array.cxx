/* Merge two arrays (not necessarily sorted) 

 O(nlogn+mlogm)+(n+m)) time complexity */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    static vector<int> merge(vector<int> a, vector<int> b){
        vector<int> res;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i = 0, j = 0;
        while(i < (int)a.size() && j < (int)b.size()){
            if(a[i] <= b[j]){
                res.emplace_back(a[i]);
                i++;
            }
            else{
                res.emplace_back(b[j]);
                j++;
            }
        }
        while(i < (int)a.size()){
            res.emplace_back(a[i]);
            i++;
        }
        while(j < (int)b.size()){
            res.emplace_back(b[j]);
            j++;
        }
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> a = {10,5,15};
    vector<int> b = {20,3,2,12};
    
    for(auto &x : Solution::merge(a,b))
        cout << x << " ";
    cout << endl;
    return 0;
}
