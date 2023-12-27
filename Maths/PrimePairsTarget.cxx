#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    static vector<vector<int>> findPrimePairs(int n) {
        const vector<bool> isPrime = sieveErato(n+1);
        vector<vector<int>> res;
        for(int i = 2; i <= n/2; ++i) {
            if(isPrime[i]&&isPrime[n-i]) {
                res.push_back({i,n-i});
            }
        }
        /*vector<vector<int>> res;
        for(int i = 0; i <= n/2; ++i) {
            if(isPrime(i)&&isPrime(n-i)) {
                res.push_back({i,n-i});
            }
        }*/
        return res;
    }
    private:
    static vector<bool> sieveErato(int n) {
        vector<bool> isPrime(n+1,true);
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i = 2; i*i < n; ++i){
            if(isPrime[i]) {
                for(int j = i*i; j < n; j+=i) {
                    isPrime[j]=false;
                }
            }
        }
        return isPrime;
    }
    /*private:
    static bool isPrime(int n) {
        if(n==0 or n==1) {
            return false;
        }
        for(int i = 2; i*i <= n; ++i) {
            if(n%i==0) {
                return false;
            }
        }
        return true;
    }*/
};

int main() {
    ios::sync_with_stdio(false);
    int n = 10;
    for(auto x : Solution::findPrimePairs(n)) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
    return 0;
}