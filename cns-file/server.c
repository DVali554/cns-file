#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

#define KEY "0123456789abcdef"

void decrypt(const unsigned char *ciphertext, int len, char *plaintext) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    int len_temp, final_len;
    EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, (unsigned char *)KEY, (unsigned char *)KEY);
    EVP_DecryptUpdate(ctx, (unsigned char *)plaintext, &len_temp, ciphertext, len);
    EVP_DecryptFinal_ex(ctx, (unsigned char *)plaintext + len_temp, &final_len);
    plaintext[len_temp + final_len] = '\0';
    EVP_CIPHER_CTX_free(ctx);
}

int main() {
    unsigned char ciphertext[128];
    char plaintext[128];
    FILE *f = fopen("server_input.bin", "rb");
    int len = fread(ciphertext, 1, sizeof(ciphertext), f);
    fclose(f);

    decrypt(ciphertext, len, plaintext);
    printf("Server: Received message: %s\n", plaintext);

    return 0;
}
