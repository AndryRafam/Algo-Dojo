/*Given a string of size N, reverse words.
Example: "I love you." --> "you love I"

Time Complexity: O(N)
Space Complexity: O(N)*/

#include <bits/stdc++.h>
using namespace std;

void reverse_word(string &s){
    stack<string> st;
    string str = "";
    for (int i = 0; i < s.length(); i++){
        if(s[i]==' '){
            st.push(str);
            str = "";
        }
        else
            str += s[i];
    }
    st.push(str);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

int main(int argc, char **argv){
    string str = "i really enjoy playing poker";
    reverse_word(str);
}