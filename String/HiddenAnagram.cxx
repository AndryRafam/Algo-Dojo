// Hidden Anagram
// https://edabit.com/challenge/vxWGJmtjpWtu36xfj

#include <bits/stdc++.h>
using namespace std;

string lowerconcat(string s){
    string t = "";
    for(auto x : s){
        if(x==' ')
            t+="";
        else
            t+=tolower(x);
    }
    return t;
}

bool is_anagram(string a, string b){
    auto d = 0;
    if(a.size()!=b.size())
        return false;
    for (auto x(0); a[x]&&b[x]; x++){
        d+=a[x];
        d-=b[x];
    }
    return (d==0 ? true:false);
}

string hiddenAnagram(string a, string b){
    string temp = "";
    for(auto i(0); i < (int)a.length(); i++){
        for(auto j(1); j <= (int)a.length()-i; j++){
            temp = a.substr(i,j);
            if(is_anagram(temp,b))
                return temp;
        }
    }
    return "Not found";
}

int main(){
    string a = "An old west action hero actor";
    string b = "Clint Eastwood";

    string s = "Bright is the moon";
    string t = "Bongo mirth";
    
    printf("%s\n",hiddenAnagram(lowerconcat(a),lowerconcat(b)).c_str()); // noldwestactio
    printf("%s\n",hiddenAnagram(lowerconcat(s),lowerconcat(t)).c_str()); // Not found
    
    return 0;
}
