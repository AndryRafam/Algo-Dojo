#include <stdio.h>
#include <math.h>

int main() {
    int baseDepart, nbChiffres;
    scanf("%d %d", &baseDepart, &nbChiffres);

    int num = 0;
    for (int i = 0; i < nbChiffres; i++) {
        int chiffre;
        scanf("%d", &chiffre);
        num = num * baseDepart + chiffre;
    }

    printf("%d\n", num);

    return 0;
}
