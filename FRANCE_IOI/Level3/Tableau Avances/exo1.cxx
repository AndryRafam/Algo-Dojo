#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int nbLine, nbCol;
    cin >> nbLine >> nbCol;
    vector<vector<char>> image(nbLine,vector<char>(nbCol,'.'));
    int nbRect;
    cin >> nbRect;
    for(auto i = 0; i < nbRect; ++i){
        int iLine1, iCol1, iLine2, iCol2;
        char color;
        cin >> iLine1 >> iCol1 >> iLine2 >> iCol2 >> color;
        for(auto line = iLine1; line <= iLine2; line++){
            for(auto col = iCol1; col <= iCol2; col++){
                image[line][col] = color;
            }
        }
    }
    for(auto line = 0; line < nbLine; ++line){
        for(auto col = 0; col < nbCol; ++col){
            cout << image[line][col];
        }
        cout << "\n";
    }
    return 0;
}