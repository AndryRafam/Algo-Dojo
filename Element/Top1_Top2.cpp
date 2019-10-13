#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static void top_two(vector<int> &v){
        int n = v.size();
        int top1 = v[n-1];
        int top2 = v[0];
        
        for(auto i = 0; i < n-1; ++i)
            if(top1 < v[i])
                top1 = v[i];
        for(auto j = 1; j < n; ++j)
            if((top2 < v[j]) && (v[j] < top1))
                top2 = v[j];
        printf("%d %d", top1,top2);
    }
};
int main(){
    vector<int> test = {1, 3, 6, 10, 11, 15};
    Solution::top_two(test);
}
