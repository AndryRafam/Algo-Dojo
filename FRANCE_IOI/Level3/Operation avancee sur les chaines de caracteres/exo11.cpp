#include <bits/stdc++.h>
using namespace std;

string cipher(const string &ciphertext, int numPage, int key){
    string res = "";
    for(auto i = 0; i < ciphertext.length(); ++i){
        if(isupper(ciphertext[i])){
            res+=char(int(ciphertext[i]+26-key-65)%26+65);
        }
        else if(islower(ciphertext[i])){
            res+=char(int(ciphertext[i]+26-key-97)%26+97);
        }
        else{
            res+=ciphertext[i];
        }
    }
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    string ciphertext = "Ikio kyz rg ykiutjk vgmk ja robxk";
    int numPage = 1;
    int key;
    if(numPage&1){
        key=3*numPage;
        cout << cipher(ciphertext,numPage,key);
    }
    else{
        key=-5*numPage;
        cout << cipher(ciphertext,numPage,key);
    }
    return 0;
}

/*FRANCE IOI SOLUTION

#include <bits/stdc++.h>
#define N 26

using namespace std;
string s,t,s1,s2;
int n;
int tab[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    getline(cin,s);
    int x;
    for(int t=2;t<=n;++t)
    {
      getline(cin,s);
      if(t%2==0)
         x=t*3;
      else x=-5*t;
      for(unsigned int i=0;i<s.length();++i)
      {
         if(s[i]>='a' && s[i]<='z')
         {
            cout<<char((s[i]-'a'-(x%N)+N)%N+'a');
         }
         else if(s[i]>='A' && s[i]<='Z')
         {
            cout<<char((s[i]-'A'-(x%N)+N)%N+'A');
         }
         else cout<<s[i];
      }
      cout<<endl;
    }
    return 0;
}
*/