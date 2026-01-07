#include <stdio.h>

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

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

long long modInverse(long long e, long long phi) {
    for (long long d = 1; d < phi; d++) {
        if ((e * d) % phi == 1)
            return d;
    }
    return -1;
}

int main() {
    long long p, q, e;
    int size;

    printf("Enter p: ");
    scanf("%lld", &p);
    printf("Enter q: ");
    scanf("%lld", &q);

    long long n = p * q;
    long long phi = (p - 1) * (q - 1);

    printf("Enter e: ");
    scanf("%lld", &e);

    if (gcd(e, phi) != 1) {
        printf("e is not coprime with phi\n");
        return 0;
    }

    long long d = modInverse(e, phi);

    printf("Enter size of message: ");
    scanf("%d", &size);

    char msg[size];
    long long P[size], C[size], D[size];

    printf("\n--- RSA ---\n");
    printf("Public Key (e,n) = (%lld,%lld)\n", e, n);
    printf("Private Key d = %lld\n\n", d);

    /* INPUT */
    for (int i = 0; i < size; i++) {
        printf("Enter char %d: ", i + 1);
        scanf(" %c", &msg[i]);
        P[i] = msg[i] - 'A';   // A=0, B=1, ...
    }

    /* ENCRYPT */
    printf("\nEncryption:\n");
    for (int i = 0; i < size; i++) {
        C[i] = modexp(P[i], e, n);
        printf("%c (%lld) -> %lld\n", msg[i], P[i], C[i]);
    }

    /* DECRYPT */
    printf("\nDecryption:\n");
    for (int i = 0; i < size; i++) {
        D[i] = modexp(C[i], d, n);
        printf("%lld -> %lld -> %c\n", C[i], D[i], (char)(D[i] + 'A'));
    }

    return 0;
}
