#include <stdio.h>
#include <string.h>

int main() {
    char plaintext[100], key[100], ciphertext[100];
    int i, keyLen;

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    printf("Enter key: ");
    scanf("%s", key);

    keyLen = strlen(key);

    for (i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = ((plaintext[i] - 'A') +
                         (key[i % keyLen] - 'A')) % 26 + 'A';
    }

    ciphertext[i] = '\0';

    printf("Ciphertext: %s", ciphertext);

    return 0;
}
