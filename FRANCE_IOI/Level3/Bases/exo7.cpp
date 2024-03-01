#include <stdio.h>

void printBinary(int num) {
    if (num > 1) {
        printBinary(num / 2);
    }
    printf("%d", num % 2);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        for (int j = 1; j <= T; j++) {
            printBinary(i * j);
            printf("\t");
        }
        printf("\n");
    }

    return 0;
}
