// Kata 19: http://codekata.com/kata/kata19-word-chains/

#include <bits/stdc++.h>
using namespace std;

bool isAdjacent(string a, string b) {
    int diff_count = 0;
    for(int i = 0; i < (int)a.size(); ++i) {
        if(a[i]!=b[i]) {
            ++diff_count;
        }
        if(diff_count > 1) {
            return false;
        }
    }
    return diff_count==1;
}

vector<string> ladder(string start,string end,vector<string> dic) {
    unordered_set<string> visited = {start};
    queue<pair<string,vector<string>>> q;
    q.push({start,{start}});
    while(!q.empty()) {
        string word = q.front().first;
        vector<string> chain = q.front().second;
        q.pop();
        if(word==end) {
            return chain;
        }
        for(auto &next_word : dic) {
            if(isAdjacent(word,next_word) && visited.find(next_word)==visited.end()) {
                vector<string> new_chain = chain;
                new_chain.push_back(next_word);
                q.push({next_word,new_chain});
            }
        }
    }
    return {};
}

int main() {
    ios::sync_with_stdio(false);
    vector<string> dic = {"cat", "cot", "cog", "dog", "lead", "load", "goad", "gold", "ruby", "rubs", "robs", "rods", "rode", "code"};
    string start; cin >> start;
    string end; cin >> end;
    for(auto &x : ladder(start,end,dic)) {
        cout << x << " ";
    }
    return 0;
}