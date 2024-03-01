#include <stdio.h>
#include <vector>

int main() {
    int entierAConvertir, baseArrivee;
    scanf("%d %d", &entierAConvertir, &baseArrivee);

    if (entierAConvertir == 0) {
        printf("1\n0\n");
        return 0;
    }

    std::vector<int> chiffres;
    while (entierAConvertir > 0) {
        chiffres.push_back(entierAConvertir % baseArrivee);
        entierAConvertir /= baseArrivee;
    }

    printf("%zu\n", chiffres.size());
    for (int i = chiffres.size() - 1; i >= 0; i--) {
        printf("%d ", chiffres[i]);
    }
    printf("\n");

    return 0;
}
