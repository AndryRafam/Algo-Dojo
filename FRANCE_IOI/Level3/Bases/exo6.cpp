#include <stdio.h>
#include <vector>
#include <math.h>

int main() {
    int B1, B2, C;
    scanf("%d %d %d", &B1, &B2, &C);

    // Convert the number from base B1 to base 10
    long long num = 0;
    for (int i = 0; i < C; i++) {
        int digit;
        scanf("%d", &digit);
        num = num * B1 + digit;
    }

    // Convert the number from base 10 to base B2
    std::vector<int> digits;
    do {
        digits.push_back(num % B2);
        num /= B2;
    } while (num > 0);

    // Print the digits in reverse order
    for (int i = digits.size() - 1; i >= 0; i--) {
        printf("%d ", digits[i]);
    }
    printf("\n");

    return 0;
}
