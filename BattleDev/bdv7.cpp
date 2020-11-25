// Bissextile year

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    for(auto i(0); i < N; i++){
        int x;
        scanf("%d",&x);
        if(x%4==0 and x%100!=0)
            printf("%s\n","BISSEXTILE");
        else if(x%400==0)
            printf("%s\n","BISSEXTILE");
        else
            printf("%s\n","NO");
    }
    return 0;
}