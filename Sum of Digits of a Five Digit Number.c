#include <stdio.h>

int main() {
    int n, sum = 0;
    scanf("%d", &n);

    // Loop until all digits are processed
    while (n > 0) {
        sum += n % 10;  // add last digit
        n /= 10;        // remove last digit
    }

    printf("%d\n", sum);
    return 0;
}
