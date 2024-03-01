#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }
    string message = "";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 26; j++) {
            if (grid[i][j] == 'O') {
                message += char('A' + j);
                grid[i][j] = '#';
            }
        }
    }
    cout << message << "\n";
    return 0;
}

/*
int main()
{
   int nbLignes;
   scanf("%d", &nbLignes);

   for (int ligne = 0; ligne < nbLignes; ligne++)
   {
      char texteLigne[26 + 1];
      scanf("%s", texteLigne);

      for (int colonne = 0; colonne < 26; colonne++)
         if (texteLigne[colonne] == 'O')
            putchar('A' + colonne);
   }

   putchar('\n');
   return 0;
}
*/

