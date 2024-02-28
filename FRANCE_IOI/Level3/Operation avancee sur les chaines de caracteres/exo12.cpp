FRANCE IOI SOLUTION

#include <iostream>
#include <string>
#include <cctype>
using namespace std;
char decaler(char lettre, char origine, int decalage)
{
   decalage = (lettre - origine + 26 + decalage) % 26;
   return (char)(origine + decalage);
}
int main()
{
   string texte;
   getline(cin,texte);
   int effectifs[26] = {0};
   for (int iCar = 0; iCar < (int)texte.length(); iCar = iCar + 1)
   {
      int indice = toupper(texte[iCar]) - 'A';
      if ((indice >= 0) && (indice < 26))
      {
         effectifs[indice] = effectifs[indice] + 1;
      }
   }
   int decalage = 0;
   for (int indice = 1; indice < 26; indice = indice + 1)
   {
      if (effectifs[indice] > effectifs[decalage])
      {
         decalage = indice;
      }
   }
   decalage = 'E' - 'A' - decalage;
   
   for (int iCar = 0; iCar < (int)texte.length(); iCar = iCar + 1)
   {
      if (isupper(texte[iCar]))
      {
         texte[iCar] = decaler(texte[iCar],'A',decalage);
      }
      else if (islower(texte[iCar]))
      {
         texte[iCar] = decaler(texte[iCar],'a',decalage);
      }
   }
   cout << texte << endl;
}
