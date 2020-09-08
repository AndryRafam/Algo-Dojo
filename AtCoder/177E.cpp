/* Coprime */

#include <bits/stdc++.h>
using namespace std;

int GCD(vector<int> arr){
    int gcd = arr[0];
    for(auto i = 1; i < (int)arr.size(); i++){
        gcd = __gcd(arr[i],gcd);
    }
    return gcd;
}

void is(vector<int> entry){
    for(auto i = 0; i < (int)entry.size()-1; i++){
        for(auto j = i+1; j < (int)entry.size(); j++){
            if(GCD(entry)==1&&__gcd(entry[i],entry[j])!=1){
                cout << "setwise" << endl;
                return;
            }
            else if(GCD(entry)!=1&&__gcd(entry[i],entry[j])!=1){
                cout << "neither" << endl;
                return;
            }
            else{
                cout << "pairwise" << endl;
                return;
            }
                
        }
    }
}

int main(){
    vector<int> tab1 = {3,4,5}; // pairwise
    vector<int> tab2 = {6,10,15}; // setwise
    vector<int> tab3 = {6,10,16}; //neither
    is(tab1); is(tab2); is(tab3);
}