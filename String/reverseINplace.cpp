#include <bits/stdc++.h>
using namespace std;

class Reverse{
public:
  static void reverse(string input){
    int mid = input.size()/2;
    for (auto i = 0; i < mid; ++i){
        swap(input[i],input[(input.size()-1)-i]);
    } 
    for (auto i = 0; i < input.size(); ++i)
        cout << input[i];
    cout << endl;
  }
};

int main(void){
  string str1 = "Shadow";
  string str2 = "Timberwolf";
  Reverse::reverse(str1);
  Reverse::reverse(str2);
}
