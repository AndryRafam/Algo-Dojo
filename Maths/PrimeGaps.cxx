// Source: https://edabit.com/challenge/ShunivMZuPRgEg7iQ

#include <bits/stdc++.h>
using namespace std;

bool prime(int n){
    if(n < 2)
        return false;
    for (auto x = 2; x*x <= n; x++){
        if(n%x==0)
            return false;
    }
    return true;
}

void prime_gaps(int g, int a, int b){
    vector<int> t;
    for(auto i = a; i <= b; i++){
        if(prime(i))
            t.emplace_back(i);
    }
    for(auto x = 0; x < (int)t.size(); x++){
        for(auto y = x+1; y < (int)t.size(); y++){
            if(t[y]-t[x]==g){
                cout << t[x] << " " << t[y] << endl;
                return;
            }
        }
    }
    cout << 0 << " " << 0 << endl;
    return;
}

int main(){
    int g = 4;
    int a = 130; int b = 200;
    prime_gaps(g,a,b); // 163 167
}