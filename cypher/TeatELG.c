#include <stdio.h>

// Modular exponentiation
long long modexp(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Modular inverse using Fermat's Little Theorem
long long modInverse(long long a, long long p) {
    return modexp(a, p - 2, p);
}

int main() {
    long long p, g, x, y;
    long long P, k;
    long long C1, C2;
    long long decrypted;

    // Key generation
    printf("Enter prime p: ");
    scanf("%lld", &p);

    printf("Enter generator g: ");
    scanf("%lld", &g);

    printf("Enter private key x: ");
    scanf("%lld", &x);

    y = modexp(g, x, p);

    printf("\nPublic key (p, g, y) = (%lld, %lld, %lld)\n", p, g, y);

    // Encryption
    printf("\nEnter plaintext P: ");
    scanf("%lld", &P);

    printf("Enter random k: ");
    scanf("%lld", &k);

    C1 = modexp(g, k, p);
    C2 = (P * modexp(y, k, p)) % p;

    printf("\nEncrypted ciphertext (C1, C2) = (%lld, %lld)\n", C1, C2);

    // Decryption
    decrypted = (C2 * modInverse(modexp(C1, x, p), p)) % p;

    printf("Decrypted plaintext = %lld\n", decrypted);

    return 0;
}
