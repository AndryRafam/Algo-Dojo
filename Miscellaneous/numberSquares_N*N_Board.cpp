/*Count the number of squares in N*N Board
Time Complexity: O(N)*/

#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    static int square_number(int n){
        if(n==1)
            return 1;
        int num = 0;
        for(auto i = 0; i < n; ++i){
            num += (n-i)*(n-i);
        }
        return num;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N = 2;
    int N = 3;
    cout << solution::square_number(N); // 5
    cout << solution::square_number(N); // 14
}
