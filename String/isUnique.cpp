/*Check if a character is unique in a string.*/

#include <bits/stdc++.h>
using namespace std;

class Answer{
    public:
        static bool isUnique(string str){
            unordered_map<char,int> hash;
            for(auto i = 0; i < str.length(); i++)
                hash[str[i]]++;
            for(auto &x : hash){
                if(x.second != 1)
                    return false;
            }return true;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    string test1 = "hello";
    string test2 = "string";
    cout << Answer::isUnique(test1) << endl;
    cout << Answer::isUnique(test2) << endl;
}
