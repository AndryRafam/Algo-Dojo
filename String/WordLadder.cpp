/*Word Ladder:

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence 
of words beginWord -> s1 -> s2 -> ... -> sk such that:

    Every adjacent pair of words differs by a single letter.
    Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
    sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest
transformation sequence from beginWord to endWord, or -1 if no such sequence exists.
*/

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false)
#define ust unordered_set

class Solution {
public:
    static int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end()){
            return 0;
        }
        queue<pair<string,int>> q;
        ust<string> visited = {beginWord};
        q.push({beginWord,1});
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            if(cur.first==endWord){
                return cur.second;
            }
            for(auto &word : wordList){
                if(visited.find(word)==visited.end() and isAdjacent(cur.first,word)){
                    visited.insert(word);
                    q.push({word,cur.second+1});
                }
            }
        }
        return 0;
    }
    private:
    static bool isAdjacent(string w, string s){
        int diff_count = 0;
        for(size_t i(0); i < w.size(); ++i){
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
    fast_io;
    cin.tie(0);
    vector<string> wordList = {"hot","dot","dog","lot","log"};
    string beginWord; cin >> beginWord;
    string endWord; cin >> endWord;
    cout << Solution::ladderLength(beginWord,endWord,wordList);
    return 0;
}
