// Bissextile year

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    for(auto i(0); i < N; i++){
        int x;
        scanf("%d",&x);
        printf("%s\n", ((x%4==0 and x%100!=0)||x%400==0) ? "BISSEXTILE":"NO");
    }
    return 0;
}
