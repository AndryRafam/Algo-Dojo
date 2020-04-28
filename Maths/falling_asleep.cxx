// AtCoder Dwango Programming Contest 6th (Problem A)

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int music(vector<pair<string,int>> pairvec, string &X){
        int count = 0;
        for(auto i = 0; i < pairvec.size(); i++){
            if(pairvec[i].first == X){
                for(auto j = i+1; j < pairvec[j].second; j++)
                    count+=pairvec[j].second;
            }
        }
        return count;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    vector<pair<string,int>> pairvec;
    string s, X; int k;
    int count = 0;
    int N; cin >> N;

    for (auto i = 0; i < N; i++){
        cin >> s >> k;
        pairvec.emplace_back(s,k);
    }

    cin >> X;
    cout << Solution::music(pairvec,X);
    return 0;
}
