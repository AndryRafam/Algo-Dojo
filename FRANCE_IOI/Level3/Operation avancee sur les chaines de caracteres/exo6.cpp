#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> freq;
string s1,s2,temp;
vector<string> arr;

int frequency(const string &word, const string &s){
    istringstream iss(s);
    while(iss >> temp){
        transform(temp.begin(),temp.end(),temp.begin(), ::tolower);
        arr.push_back(temp);
    }
    for(auto &w : arr){
        freq[w]++;
    }
    for(auto &w : freq){
        if(w.first==word){
            return w.second;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    getline(cin,s1);
    getline(cin,s2);
    cout << frequency(s1,s2);
    return 0;
}

/*FRANCE IOI SOLUTION

#include <bits/stdc++.h>
using namespace std;

int main()
{
   string cible;
   cin >> cible;
   for (int iCar = 0; iCar < (int)cible.length(); iCar = iCar + 1)
   {
      cible[iCar] = toupper(cible[iCar]);
   }
   int effectifCible = 0;
   string mot;
   cin >> mot;
   while (!cin.fail())
   {
      for (int iCar = 0; iCar < (int)mot.length(); iCar = iCar + 1)
      {
         mot[iCar] = toupper(mot[iCar]);
      }
      if (mot == cible)
      {
         effectifCible = effectifCible + 1;
      }
      cin >> mot;
   }
   cout << effectifCible << endl;
}
*/