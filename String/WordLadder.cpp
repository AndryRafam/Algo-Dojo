/*Word Ladder:
You are given a dictionary of words and a start word. Your task is to transform the start word into the target word
by changing exactly one character at a time. At each step, the intermediate word must be in the dictionary.
Find the minimum number of steps required to transform the start word into the target word. 
If it's not possible, return -1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    static int word_ladder(string start, string target, vector<string> word_list){
        if(find(word_list.begin(),word_list.end(),target)==word_list.end()){
            return -1;
        }
        queue<pair<string,int>> q;
        unordered_set<string> visited = {start};
        q.push({start,1});
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            if(cur.first==target){
                return cur.second;
            }
            for(auto &word : word_list){
                if(visited.find(word)==visited.end() and isAdjacent(cur.first,word)){
                    visited.insert(word);
                    q.push({word,cur.second+1});
                }
            }
        }
        return -1;
    }
    private:
    static bool isAdjacent(string w, string s){
        int diff_count = 0;
        for(auto i(0); i < w.size(); ++i){
            if(w[i]!=s[i]){
                ++diff_count;
            }
            if(diff_count > 1){
                return false;
            }
        }
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<string> word_list = {"hot", "dot", "dog", "lot", "log", "cog"};
    string start; cin >> start;
    string target; cin >> target;
    cout << Solution::word_ladder(start,target,word_list) << "\n";
    return 0;
}