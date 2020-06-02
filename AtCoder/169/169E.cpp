#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    static double median(double a, double b){
        return (a+b)/2;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    vector<pair<double,double>> pairvec;
    int N; cin >> N;
    float x, y;
    set<double> s;
    for(auto i(0); i < N; i++){
        cin >> x >> y;
        pairvec.emplace_back(x,y);
    }
    for(auto i(0); i!=N; i++){
        for(auto j(0); j!=N; j++){
            double med = Solution::median(pairvec[i].first,pairvec[j].second);
            s.insert(med);
        }
    }
    cout << s.size() << endl;
    return 0;
}
