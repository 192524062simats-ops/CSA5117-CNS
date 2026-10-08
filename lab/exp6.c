#include <stdio.h>
#include <string.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int modInverse(int a) {
    for (int i = 1; i < 26; i++)
        if ((a * i) % 26 == 1)
            return i;
    return -1;
}

int main() {
    char cipher[500];

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);

    printf("\nPossible plaintexts:\n");

    for (int a = 1; a < 26; a++) {
        if (gcd(a, 26) != 1)
            continue;

        int inverse = modInverse(a);

        for (int b = 0; b < 26; b++) {
            printf("a=%d b=%d: ", a, b);

            for (int i = 0; cipher[i] != '\0'; i++) {
                if (cipher[i] >= 'A' && cipher[i] <= 'Z') {
                    int c = cipher[i] - 'A';
                    int p = (inverse * (c - b + 26)) % 26;
                    printf("%c", p + 'A');
                }
                else {
                    printf("%c", cipher[i]);
                }
            }

            printf("\n");
        }
    }

    return 0;
}
