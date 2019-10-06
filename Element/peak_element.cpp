#include <bits/stdc++.h>
using namespace std;

class Answer{
    public:
        static bool peak_elt(vector<int> v){
            for(auto i = 0; i < v.size(); i++){
                if((v[i] >= v[i+1])&&(v[i] >= v[i-1]))
                    return true;
            }
        }
};

int main(){
    vector<int> tab = {1,3,3,2};
    if(Answer::peak_elt(tab))
        cout << 1 << endl;
    else
        cout << 0 << endl;
}
