#include <bits/stdc++.h> // O(nLogn) time complexity
using namespace std;

class Answer{
    public:
        static void missing(vector<int> v){
            int miss_number;
            sort(v.begin(), v.end());
            for (auto i = 0; i < v.size(); i++){
                if ((v[i] >= 0) && (v[i]+1 < v[i+1])){
                    miss_number = v[i]+1;
                    cout << miss_number << endl;
                    break;
                }
                else
                    continue;
            }
        }
};

int main(){
    vector<int> v = {1,2,3,4,6}; // 5
    Answer::missing(v);
    vector<int> v2 = {0,-10,1,2,5,-20}; // 3
    Answer::missing(v2);
}
