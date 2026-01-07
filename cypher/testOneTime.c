#include <stdio.h>
#include <string.h>

int main() {
    char plaintext[100];
    char key[100][6];     // 5 bits + '\0'
    char ciphertext[100];

    printf("Enter plaintext (A-Z): ");
    scanf("%s", plaintext);

    int len = strlen(plaintext);

    printf("Enter secret key (5-bit binary per char)\n");
    for (int i = 0; i < len; i++) {
        printf("Key for %c: ", plaintext[i]);
        scanf("%5s", key[i]);
    }

    for (int i = 0; i < len; i++) {
        int p = plaintext[i] - 'A';   // A-Z → 0-25
        int k = 0;

        // แปลง binary key → decimal
        for (int j = 0; j < 5; j++) {
            k = (k << 1) | (key[i][j] - '0');
        }

        int c = p ^ k;               // XOR
        ciphertext[i] = c + 'A';     // decimal → char
    }

    ciphertext[len] = '\0';

    printf("\nCiphertext: %s\n", ciphertext);

    return 0;
}
