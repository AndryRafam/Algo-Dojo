#include <bits/stdc++.h>
using namespace std;

bool checkWin(vector<vector<int>> &board, int player){
    int N = board.size();
    
    for(auto r = 0; r < N; ++r){
        int count = 0;
        for(auto c = 0; c < N; ++c){
            if(board[r][c]==player){
                count++;
                if(count==5){
                    return true;
                }
            }
            else{
                count = 0;
            }
        }
    }

    for(auto c = 0; c < N; ++c){
        int count = 0;
        for(auto r = 0; r < N; ++r){
            if(board[r][c]==player){
                count++;
                if(count==5){
                    return true;
                }
            }
            else{
                count = 0;
            }
        }
    }

    for(auto r = 0; r < N-4; ++r){
        for(auto c = 0; c < N-4; ++c){
            bool win = true;
            for(auto k = 0; k < 5; ++k){
                if(board[r+k][c+k]!=player){
                    win = false;
                    break;
                }
            }
            if(win){
                return true;
            }
        }
    }

    for(auto r = 0; r < N-4; ++r){
        for(auto c = N-1; c >= 4; --c){
            bool win = true;
            for(auto k = 0; k < 5; ++k){
                if(board[r+k][c-k]!=player){
                    win = false;
                    break;
                }
            }
            if(win){
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    int N; cin >> N; cin.ignore();
    vector<vector<int>> board(N,vector<int>(N));
    for(auto i = 0; i < N; ++i){
        for(auto j = 0; j < N; ++j){
            cin >> board[i][j];
        }
    }
    bool player1Win = checkWin(board,1);
    bool player2Win = checkWin(board,2);
    if(player1Win){
        cout << 1 << "\n";
    }
    else if(player2Win){
        cout << 2 << "\n";
    }
    else{
        cout << 0 << "\n";
    }
    return 0;
}

/* SOLUTION FRANCE IOI

#include <iostream>
using namespace std;
const int MAX_TAILLE = 40;
int delta[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
int couleur[MAX_TAILLE][MAX_TAILLE];
int taillePlateau;
int couleurPion(int lin, int col)
{
   if ((lin < 0) || (lin >= taillePlateau) ||
       (col < 0) || (col >= taillePlateau))
      return 0;
   return couleur[lin][col];
}
int numeroGagnant()
{
   for (int idJoueur = 1; idJoueur<= 2; idJoueur++)
      for (int lin = 0; lin < taillePlateau; lin++)
         for (int col = 0; col < taillePlateau; col++)
            for (int dir = 0; dir < 4; dir++)
            {
               int curLin = lin, curCol = col;
               int nbAlignes = 0;
               for (int longueur = 0; longueur < 5; longueur++)
               {
                  if (couleurPion(curLin, curCol) == idJoueur)
                     nbAlignes++;
                  curLin += delta[dir][0];
                  curCol += delta[dir][1];
               }
               if (nbAlignes == 5)
                  return idJoueur;
            }
   return 0;
}
int main()
{
   cin >> taillePlateau;
   for (int lin = 0; lin < taillePlateau; lin++)
      for (int col = 0; col < taillePlateau; col++)
         cin >> couleur[lin][col];
   cout << numeroGagnant() << endl;
   return 0;
}
*/