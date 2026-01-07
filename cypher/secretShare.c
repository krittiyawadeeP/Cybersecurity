#include <stdio.h>

#define MAX 10

// mod p (prime)
long long mod(long long a, long long p) {
    long long r = a % p;
    return (r < 0) ? r + p : r;
}

// fast power
long long modexp(long long base, long long exp, long long p) {
    long long res = 1;
    base %= p;
    while (exp > 0) {
        if (exp & 1)
            res = (res * base) % p;
        base = (base * base) % p;
        exp >>= 1;
    }
    return res;
}

// modular inverse (Fermat)
long long modInverse(long long a, long long p) {
    return modexp(a, p - 2, p);
}

// polynomial evaluation f(x)
long long f(long long x, long long coeff[], int k, long long p) {
    long long result = 0;
    for (int i = 0; i < k; i++) {
        result = mod(result + coeff[i] * modexp(x, i, p), p);
    }
    return result;
}

// reconstruct secret using Lagrange
long long reconstruct(long long x[], long long y[], int k, long long p) {
    long long secret = 0;

    for (int i = 0; i < k; i++) {
        long long num = 1, den = 1;

        for (int j = 0; j < k; j++) {
            if (i != j) {
                num = mod(num * (-x[j]), p);
                den = mod(den * (x[i] - x[j]), p);
            }
        }

        long long li = mod(num * modInverse(den, p), p);
        secret = mod(secret + y[i] * li, p);
    }

    return secret;
}

int main() {
    int n, k;
    long long p;

    printf("Enter prime p: ");
    scanf("%lld", &p);

    printf("Enter number of shares n: ");
    scanf("%d", &n);

    printf("Enter threshold k: ");
    scanf("%d", &k);

    long long coeff[MAX];
    printf("\nEnter secret (a0): ");
    scanf("%lld", &coeff[0]);

    for (int i = 1; i < k; i++) {
        printf("Enter coefficient a%d: ", i);
        scanf("%lld", &coeff[i]);
    }

    long long xs[MAX], ys[MAX];

    printf("\nGenerated shares:\n");
    for (int i = 0; i < n; i++) {
        xs[i] = i + 1;
        ys[i] = f(xs[i], coeff, k, p);
        printf("Share %d: (%lld, %lld)\n", i + 1, xs[i], ys[i]);
    }

    printf("\n--- Reconstruction using first %d shares ---\n", k);

    long long rx[MAX], ry[MAX];
    for (int i = 0; i < k; i++) {
        rx[i] = xs[i];
        ry[i] = ys[i];
    }

    long long secret = reconstruct(rx, ry, k, p);
    printf("Recovered secret = %lld\n", secret);

    return 0;
}
