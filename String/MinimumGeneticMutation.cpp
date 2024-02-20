/*
A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene
where one mutation is defined as one single character changed in the gene string.

    For example, "AACCGGTT" --> "AACCGGTA" is one mutation.

There is also a gene bank bank that records all the valid gene mutations.
A gene must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number
of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.
*/

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false)
#define ust unordered_set

class Solution {
    public:
    static int minMutation(const string startGene, const string endGene, vector<string>& bank) {
        if(find(bank.begin(),bank.end(),endGene)==bank.end()) {
            return -1;
        }
        ust<string> visited;
        queue<pair<string,int>> q;
        q.push({startGene,0});
        
        while(!q.empty()) {
            auto [gene,mutations] = q.front();
            q.pop();
            visited.insert(gene);
            if(gene==endGene) {
                return mutations;
            }
            for(int i = 0; i < 8; ++i) {
                for(char c : {'A','C','G','T'}) {
                    string newGene = gene;
                    newGene[i] = c;
                    if(visited.count(newGene) || find(bank.begin(),bank.end(),newGene)==bank.end()) {
                        continue;
                    }
                    q.push({newGene,mutations+1});
                }
            }
        }
        return -1;
    }
};

int main() {
    fast_io;
    cin.tie(0);
    vector<string> bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    string startGene; cin >> startGene;
    string endGene; cin >> endGene;
    cout << Solution::minMutation(startGene,endGene,bank);
    return 0;
}