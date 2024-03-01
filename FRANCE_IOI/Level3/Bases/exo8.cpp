#include <stdio.h>

int main() {
    int N;
    scanf("%X", &N);

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%X", &num);
        sum += num;
    }

    printf("%X\n", sum / N);

    return 0;
}
