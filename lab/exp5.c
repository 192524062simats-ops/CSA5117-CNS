#include <stdio.h>
#include <string.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    char plaintext[100], ciphertext[100];
    int a, b, i, p, c;

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    if (gcd(a, 26) != 1) {
        printf("Invalid value of a");
        return 0;
    }

    for (i = 0; plaintext[i] != '\0'; i++) {
        p = plaintext[i] - 'A';
        c = (a * p + b) % 26;
        ciphertext[i] = c + 'A';
    }

    ciphertext[i] = '\0';

    printf("Ciphertext: %s", ciphertext);

    return 0;
}
