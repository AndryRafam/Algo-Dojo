/* Intersection of Three sorted array with multiple duplicates */

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static void triple_intersection(vector<int> &v1,vector<int> &v2, vector<int> &v3){
        vector<int> result;
        for(auto i = 0; i < v3.size(); ++i){
            if(binary_search(v1.begin(),v1.end(),v3[i]) && binary_search(v2.begin(),v2.end(),v3[i]))
                    result.emplace_back(v3[i]);
        }
        unordered_set<int> s;
        for(auto &i : result)
            s.insert(i);
        for(auto &x : s)
        	cout << x << " ";
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    vector<int> t1 = {1, 5, 10, 20, 40, 80, 80, 120};
    vector<int> t2 = {6, 7, 20, 20, 80, 80, 100, 120};
    vector<int> t3 = {3, 4, 15, 20, 20, 30, 70, 80, 80, 120};
    Solution::triple_intersection(t1,t2,t3);
}
