#include <bits/stdc++.h>
using namespace std;

int main()
{
   string acronyme;
   cin >> acronyme;
   int nbMots = acronyme.length();
   int nbLivres;
   cin >> nbLivres;
   cin.ignore();
   for (int iLivre = 0; iLivre < nbLivres; iLivre = iLivre + 1)
   {
      string titre;
      getline(cin,titre);
      char precedent = ' ';
      int iMot = 0;
      bool correspondance = true;
      for (int iCar = 0; iCar < (int)titre.length(); iCar = iCar + 1)
      {
         if ((precedent == ' ') && (titre[iCar] != ' '))
         {
            titre[iCar] = toupper(titre[iCar]);
            if (correspondance)
               correspondance = (iMot < nbMots) && (acronyme[iMot] == titre[iCar]);
            iMot = iMot + 1;
         }
         else
         {
            titre[iCar] = tolower(titre[iCar]);
         }
         precedent = titre[iCar];
      }
      if (correspondance && (iMot == nbMots))
      {
         cout << titre << endl;
      }
   }
}