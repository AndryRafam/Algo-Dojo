/* Sorted - Rotated Array */ 

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int search(vector<int> tab, int target){
        int pivot_max = distance(tab.begin(),max_element(tab.begin(),tab.end()));
        int pivot_min = distance(tab.begin(),min_element(tab.begin(),tab.end()));
        
        if(binary_search(tab.begin(),tab.begin()+pivot_max,target))
            return target;
        else if(binary_search(tab.begin()+pivot_min,tab.end(),target))
            return target;
        else
            return -1;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    vector<int> v = {4,5,6,7,0,1,2};
    cout << Solution::search(v,0);
}
