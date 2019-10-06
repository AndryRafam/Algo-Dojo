/*Find all permutations of the given string using next_permutation STL*/

#include <bits/stdc++.h>
using namespace std;

class Answer{
    public:
        static void permute(string s){
            sort(s.begin(),s.end());
            do{
                cout << s << " ";
            }while(next_permutation(s.begin(),s.end()));
        }
};

int main(){
    string test = "ABSG";
    Answer::permute(test);
    return 0;
}
