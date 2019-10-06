/*Multiple duplicate*/
#include <bits/stdc++.h>
using namespace std;

class Answer{
    public:
        static void find_duplicate(vector<int> tab){
            set<int> s;
            sort(tab.begin(),tab.end());
            for(auto i = 0; i < tab.size(); i++){
                if(tab[i]==tab[i+1])
                    s.insert(tab[i]);
            }
            for(auto x : s)
                cout << x << " ";
        }
};

int main(){
    vector<int> v = {1,5,3,6,5,3,2,3};
    Answer::find_duplicate(v);
}
