// 3 Divisors
// Given a value N. The task is to find how many numbers less than or equal 
// to N have numbers of divisors exactly equal to 3.

#include <bits/stdc++.h>
using namespace std;

bool three_div(int N){
    auto div = 0;
    for(auto x(1); x <= N; x++){
        if(N%x==0)
            div++;
    }
    return(div==3 ? true:false);
}

int main(){
    int N = 30;
    int ct = 0;
    for(auto x(1); x <= N; x++){
        if(three_div(x))
            ct++;
    }
    printf("%d\n",ct); // 3
    return 0;
}