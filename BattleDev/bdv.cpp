#include <bits/stdc++.h>
using namespace std;

int max_count(string s){
    int n = s.length();
    int i = 0;
    int count = 0;
    vector<int> temp;
    while(n/2+i < n){
        for(auto j = i; j < n/2+i; ++j){
            if(s[j]=='x'){
                count+=1;
                temp.emplace_back(count);
            }
        }
        i++;
        count = 0;
    }
    sort(temp.begin(),temp.end());
    return temp[temp.size()-1];
}

int main(){
    string test = "xxooxxoxoooxxxoooxoxoxxooxxxoooxoxxxoxxxoxxooxxxxoxxxxoxoooooxoooooooxooxxxoxxoxxxoxooxxxoxoxxxoxxox";
    printf("%d",max_count(test));
    return 0;
}
