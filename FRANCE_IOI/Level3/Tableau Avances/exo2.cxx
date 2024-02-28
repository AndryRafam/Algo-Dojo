#include <bits/stdc++.h>
using namespace std;

set<int> sumLine;
set<int> sumCol;
set<int> sumDiag1;
set<int> sumDiag2;

int sumR = 0;
int sumC = 0;
int sumD1 = 0;
int sumD2 = 0;

bool isMagic(vector<vector<int>> &board){
    
    for(auto row = 0; row < board.size(); row++){
        for(auto col = 0; col < board[0].size(); col++){
            sumR+=board[row][col];
        }
        sumLine.insert(sumR);
        sumR = 0;
    }
    for(auto row = 0; row < board.size(); row++){
        for(auto col = 0; col < board[0].size(); col++){
            sumC+=board[col][row];
        }
        sumCol.insert(sumC);
        sumC = 0;
    }
    for(auto row = 0; row < board.size(); row++){
        sumD1+=board[row][row];
    }
    sumDiag1.insert(sumD1);

    for(auto row = 0; row < board.size(); row++){
        sumD2+=board[row][board.size()-row-1];
    }
    sumDiag2.insert(sumD2);

    if(sumLine.size()==1 && sumCol.size()==1 && sumDiag1.size()==1 && sumDiag2.size()==1 && sumLine.find(sumC)!=sumLine.end() && sumLine.find(sumD1)!=sumLine.end() && sumLine.find(sumD2)!=sumLine.end()){
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    vector<vector<int>> arr;
    int N; cin >> N;
    cin.ignore();
    for(auto i = 0; i < N; ++i){
        for(auto j = 0; j < N; ++j){
            cin >> arr[i][j];
        }
    }
    cout << (isMagic(arr) ? "no":"yes");
    return 0;
}

/*FRANCE IOI SOLUTION

#include <iostream>
using namespace std;
const int MAX_TAILLE = 20;
int nombresCarre[MAX_TAILLE][MAX_TAILLE];
int tailleGrille;
int totalPourDirection(int linDepart, int colDepart, int deltaLin, int deltaCol)
{
   int lin = linDepart, col = colDepart, total = 0;
   for (int position = 0; position < tailleGrille; position++)
   {
      total += nombresCarre[lin][col];
      lin += deltaLin;
      col += deltaCol;
   }
   return total;
}
bool totauxCorrects()
{
   int total = totalPourDirection(0, 0, 1, 1);
   
   if (totalPourDirection(0, tailleGrille - 1, 1, -1) != total)
      return false;
   
   for (int ligne = 0; ligne < tailleGrille; ligne++)
      if (totalPourDirection(ligne, 0, 0, 1) != total)
         return false;
   
   for (int colonne = 0; colonne < tailleGrille; colonne++)
      if (totalPourDirection(0, colonne, 1, 0) != total)
         return false;
   return true;
}
bool tousNombresPresents()
{
   int maxVal = tailleGrille * tailleGrille + 1;
   int nombrePresent[maxVal];
   for (int nombre = 0; nombre < maxVal; nombre++)
      nombrePresent[nombre] = 0;
   for (int ligne = 0; ligne < tailleGrille; ligne++)
      for (int colonne = 0; colonne < tailleGrille; colonne++)
      {
         int valeurCase = nombresCarre[ligne][colonne];
         if ((valeurCase <= 0) || (valeurCase >= maxVal))
            return false;
         if (nombrePresent[valeurCase] != 0)
            return false;
         nombrePresent[valeurCase]++;
      }
   return true;
}
int main()
{
   cin >> tailleGrille;
   for (int ligne = 0; ligne < tailleGrille; ligne++)
      for (int colonne = 0; colonne < tailleGrille; colonne++)
         cin >> nombresCarre[ligne][colonne];
   if (tousNombresPresents() && totauxCorrects())
      cout << "yes" << endl;
   else
      cout << "no" << endl;
   return 0;
}
*/