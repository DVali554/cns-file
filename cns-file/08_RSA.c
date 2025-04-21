#include <stdio.h>

long long modPow(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        exp /= 2;
        base = (base * base) % mod;
    }
    return res;
}

int main() {
    long long p = 3, q = 11, n = p * q, e = 3, msg = 5;
    long long c = modPow(msg, e, n);
    printf("Encrypted: %lld\n", c);
    return 0;
}