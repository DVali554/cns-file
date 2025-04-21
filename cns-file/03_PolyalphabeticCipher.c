#include <stdio.h>
#include <string.h>

void polyEncrypt(char *msg, char *key) {
    int msgLen = strlen(msg), keyLen = strlen(key), j = 0;
    for (int i = 0; i < msgLen; i++) {
        if (msg[i] >= 'A' && msg[i] <= 'Z') {
            msg[i] = ((msg[i] - 'A' + (key[j % keyLen] - 'A')) % 26) + 'A';
            j++;
        }
    }
}

int main() {
    char msg[100], key[100];
    printf("Enter UPPERCASE message: ");
    fgets(msg, sizeof(msg), stdin);
    msg[strcspn(msg, "\n")] = '\0';  // Remove newline character if it exists

    printf("Enter UPPERCASE key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';  // Remove newline character if it exists

    polyEncrypt(msg, key);
    printf("Encrypted: %s\n", msg);
    return 0;
}
