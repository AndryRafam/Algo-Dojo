#include <stdio.h>

void printBinary(unsigned int num) {
    if (num > 1) {
        printBinary(num / 2);
    }
    printf("%d", num % 2);
}

int main() {
    unsigned int num;
    scanf("%u", &num);
    printBinary(num);
    printf("\n");
    return 0;
}