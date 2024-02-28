#include <bits/stdc++.h>
using namespace std;

#define N 8

int dx[N] = {2,2,-2,-2,1,1,-1,-1};
int dy[N] = {1,-1,1,-1,2,2,-2,-2};

bool isValid(vector<vector<char>> &chessBoard)
{
    for(auto i = 0; i < N; ++i)
    {
        for(auto j = 0; j < N; ++j)
        {
            if(chessBoard[i][j]=='C')
            {
                for(auto k = 0; k < N; k++)
                {
                    if(i+dx[k]>=0 && i+dx[k]<N && j+dy[k]>=0 && j+dy[k]<N)
                    {
                        if(chessBoard[i+dx[k]][j+dy[k]]>='a' && chessBoard[i+dx[k]][j+dy[k]]<='z')
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    vector<vector<char>> chessBoard(N,vector<char>(N));
    for(auto i = 0; i < N; ++i)
    {
        for(auto j = 0; j < N; ++j)
        {
            cin >> chessBoard[i][j];
        }
    }
    cout << (isValid(chessBoard)? "yes":"no");
    return 0;
}

/* FRANCE IOI SOLUTION

#include <iostream>
using namespace std;
char plateau[8][9];
int delta[8][2] = {{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
int dansPlateau(int lin, int col)
{
   return ((lin >= 0) && (lin < 8) && (col >= 0) && (col < 8));
}
bool peutAttaquer()
{
   for(int lin = 0 ; lin < 8 ; lin++)
      for(int col = 0 ; col < 8 ; col++)
         if (plateau[lin][col] == 'C')
            for(int direction = 0; direction < 8 ; direction++)
            {
               const int linDest = lin + delta[direction][0];
               const int colDest = col + delta[direction][1];
               if(dansPlateau(linDest, colDest) && islower(plateau[linDest][colDest]))
                  return true;
            }
   return false;
}
int main()
{
   for(int lin = 0 ; lin < 8 ; lin++)
      cin >> plateau[lin];
   if (peutAttaquer())
      cout << "yes" << endl;
   else
      cout << "no" << endl;
   return 0;
}
*/