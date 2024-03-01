#include <stdio.h>

int main() {
    char bit;
    int num = 0;

    while (scanf("%c", &bit) != EOF) {
        if (bit == '0' || bit == '1') {
            num = num * 2 + (bit - '0');
        }
    }

    printf("%d\n", num);

    return 0;
}
