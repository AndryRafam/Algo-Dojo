#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static void triple_intersection(vector<int> &v1,vector<int> &v2, vector<int> &v3){
        for(auto i = 0; i < v3.size(); ++i){
            if(binary_search(v1.begin(),v1.end(),v3[i]))
                if(binary_search(v2.begin(),v2.end(),v3[i]))
                    printf("%d ",v3[i]);
        }
    }
};
int main(){
    vector<int> t1 = {1, 5, 10, 20, 40, 80};
    vector<int> t2 = {6, 7, 20, 80, 100};
    vector<int> t3 = {3, 4, 15, 20, 30, 70, 80, 120};
    Solution::triple_intersection(t1,t2,t3);
}
