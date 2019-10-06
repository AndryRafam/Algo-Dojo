/*Given two unsorted arrays, find all pairs whose sum is a given number - O(max(n,m)) complexity*/

#include <bits/stdc++.h>
using namespace std;

class Answer{
    public:
        static void find_pairs(vector<int> v1, vector<int> v2, int sum){
            unordered_set<int> s;
            for(auto i = 0; i < v1.size(); i++)
                s.insert(v1[i]);
            for(auto j = 0; j < v2.size(); j++)
                if(s.find(sum-v2[j]) != s.end())
                    cout << sum-v2[j] << " " << v2[j] << endl;
        }
};

int main(){
    vector<int> tab1 = {1, 2, 3, 7, 5, 4 };
    vector<int> tab2 = {0, 7, 4, 3, 2, 1 };
    Answer::find_pairs(tab1,tab2,8);
}
