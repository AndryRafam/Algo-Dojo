/*Next Greater element - O(n) complexity*/

#include <bits/stdc++.h>
using namespace std;

class Answer{
    public:
        static void next_greater(vector<int> v){
            stack<int> s;
            for(auto i = 0; i < v.size(); i++){
                if(s.empty()){
                    s.push(v[i]);
                    continue;
                }
                while(!s.empty() && s.top() < v[i]){
                    cout << v[i] << " ";
                    s.pop();
                }
                s.push(v[i]);
            }
            while(!s.empty()){
                cout << -1 << " ";
                s.pop();
            }
        }
};

int main(){
    vector<int> tab1 = {1,3,2,4};
    vector<int> tab2 = {4,3,2,1};
    Answer::next_greater(tab1); cout << "\n\n";
    Answer::next_greater(tab2);
}
