#include <bits/stdc++.h>
using namespace std;

class Answer{
    public:
        static void HighestProduct_3(vector<int> v){
            int product = 1;
            if(v.size() < 3)
                exit(0);
            sort(v.begin(),v.end());
            for(auto i = 0; i < 3; i++)
                product *= v[v.size()-1-i];
            cout << product << endl;
        }
};

int main(){
    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2 = {6, 1, 3, 5, 7, 8, 2};
    vector<int> v3 = {-5, 4, 8, 2, 3};
    vector<int> v4 = {-10, 1, 3, 2, -10};
    Answer::HighestProduct_3(v1);
    Answer::HighestProduct_3(v2);
    Answer::HighestProduct_3(v3);
    Answer::HighestProduct_3(v4);
    return 0;
}
