/*Check if a character is unique in a string.*/

#include <bits/stdc++.h>
using namespace std;

class Answer{
    public:
        static bool isUnique(string str){
            map<char,int> hash;
            for(auto i = 0; i < str.length(); i++)
                hash[str[i]]++;
            for(auto &x : hash){
                if(x.second != 1)
                    return false;
            }return true;
        }
};

int main(){
    string test1 = "hello";
    string test2 = "string";
    if(Answer::isUnique(test1))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    if(Answer::isUnique(test2))
        cout << 1 << endl;
    else
        cout << 0 << endl;
}
