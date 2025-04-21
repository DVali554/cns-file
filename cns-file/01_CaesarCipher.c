#include <stdio.h>
#include <string.h>

void caesarEncrypt(char *msg, int shift) {
    int i;
    for (i = 0; msg[i] != '\0'; i++) {
        if (msg[i] >= 'A' && msg[i] <= 'Z')
            msg[i] = ((msg[i] - 'A' + shift) % 26) + 'A';
        else if (msg[i] >= 'a' && msg[i] <= 'z')
            msg[i] = ((msg[i] - 'a' + shift) % 26) + 'a';
    }
}

int main() {
    char msg[100];
    int shift = 3;
    printf("Enter message: ");
    fgets(msg, sizeof(msg), stdin);
    msg[strcspn(msg, "\n")] = '\0';  // Remove trailing newline
    caesarEncrypt(msg, shift);
    printf("Encrypted: %s\n", msg);
    return 0;
}
