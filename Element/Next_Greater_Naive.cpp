/*Next Greater element - Naive approach
Complexity: O(n²)*/

#include <bits/stdc++.h>
using namespace std;

class Answer{
    public:
        static void next_greater(vector<int> v){
            for(auto i = 0; i < v.size(); i++){
                int next = -1;
                for(auto j = i+1; j < v.size(); j++){
                    if(v[j]>=v[i]){
                        next = v[j];
                        break;
                    }
                }
                cout << next << " ";
            }
        }
};

int main(){
    vector<int> tab1 = {4,3,2,1};
    vector<int> tab2 = {1,3,2,4};
    Answer::next_greater(tab1);
    cout << "\n\n";
    Answer::next_greater(tab2);
}
