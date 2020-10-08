/* Most frequent word in array.
   If there is a tie between word, print the first in alphabetical order.
   O(NlogN + M) time complexity, where N is size of the array and M is the size of the map */


#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static void freq (vector<string> vec){
        map<string,int> hash;
        for(auto &x : vec)
            hash[x]++;
        int max = 0;
        string s;
        for(auto &itr : hash){
            if(max < itr.second){
                max = itr.second;
                s = itr.first;
            }
        }
        cout << s << endl;
        return;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<string> vec = {"jones","paul","jones","peter","jones","peter","jackson","peter"};
    Solution::freq(vec);
    return 0;
}
