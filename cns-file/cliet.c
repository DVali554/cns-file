#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/hmac.h>

#define KEY "0123456789abcdef" // 16-byte AES key
#define HMAC_KEY "hmacsecret"

void encrypt(const char *plaintext, unsigned char *ciphertext, int *len) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    int len_temp;
    EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, (unsigned char *)KEY, (unsigned char *)KEY);
    EVP_EncryptUpdate(ctx, ciphertext, len, (unsigned char *)plaintext, strlen(plaintext));
    EVP_EncryptFinal_ex(ctx, ciphertext + *len, &len_temp);
    *len += len_temp;
    EVP_CIPHER_CTX_free(ctx);
}

int main() {
    char message[] = "Hello Secure World!";
    unsigned char ciphertext[128];
    int cipher_len;

    // Encrypt
    encrypt(message, ciphertext, &cipher_len);

    // HMAC
    unsigned char *hmac = HMAC(EVP_sha256(), HMAC_KEY, strlen(HMAC_KEY),
                                ciphertext, cipher_len, NULL, NULL);

    FILE *f = fopen("proxy_input.bin", "wb");
    fwrite(ciphertext, 1, cipher_len, f);
    fwrite(hmac, 1, 32, f); // SHA256 = 32 bytes
    fclose(f);

    printf("Client: Encrypted and signed message sent to proxy.\n");
    return 0;
}
