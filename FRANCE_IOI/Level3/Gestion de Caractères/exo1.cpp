#include <bits/stdc++.h>
using namespace std;

void batAll(string &name, int age){
    vector<pair<char,int>> letterNumber;
    for(auto _i = 0; _i < 26; _i++){
        letterNumber.push_back({char(65+_i),_i+1});
    }
    for(auto &x : letterNumber){
        if(name[0]==x.first){
            cout << x.second;
        }
    }
    for(auto &y : letterNumber){
        if(age==y.second){
            cout << y.first;
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    string name; cin >> name;
    int age; cin >> age;
    batAll(name,age);
    return 0;
}

/*Solution France IOI

#include <iostream>
#include <string>
using namespace std;
int main()
{
   string nomAuteur;
   cin >> nomAuteur;
   int ageFils;
   cin >> ageFils;
   int batiment = nomAuteur[0] - 'A' + 1;
   char allee = ageFils - 1 + 'A';
   cout << batiment << allee << endl;
}
*/