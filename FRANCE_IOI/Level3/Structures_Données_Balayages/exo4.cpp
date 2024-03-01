#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    cin.ignore();

    string expression;
    getline(cin,expression);

    stack<char> st;
    for(char c : expression) {
        if(c=='(') {
            st.push(c);
        }
        else if(c==')') {
            if(st.empty()) {
                cout << 0;
                return 0;
            }
            st.pop();
        }
    }
    cout << (st.empty() ? 1:0);
    return 0;
}