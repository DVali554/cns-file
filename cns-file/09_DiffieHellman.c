#include <stdio.h>

int power(int base, int exp, int mod) {
    int res = 1;
    while (exp--) res = (res * base) % mod;
    return res;
}

int main() {
    int p = 23, g = 5, a = 6, b = 15;
    int A = power(g, a, p);
    int B = power(g, b, p);
    int key1 = power(B, a, p);
    int key2 = power(A, b, p);
    printf("Shared key: %d\n", key1);
    return 0;
}