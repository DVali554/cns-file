#include <stdio.h>
#include <string.h>

void playfairEncrypt(char *msg) {
    for (int i = 0; i < strlen(msg); i += 2) {
        char a = msg[i], b = (i + 1 < strlen(msg)) ? msg[i + 1] : a;
        if (a == b) b = 'X';  // If characters are same, replace with 'X'
        printf("%c%c", a, b);
    }
    printf("\n");
}

int main() {
    char msg[100];
    printf("Enter message: ");
    fgets(msg, sizeof(msg), stdin);
    msg[strcspn(msg, "\n")] = '\0';  // Remove newline
    for (int i = 0; i < strlen(msg); i++) if (msg[i] == 'J') msg[i] = 'I';  // Replace 'J' with 'I'
    playfairEncrypt(msg);  // Encrypt the message
    return 0;
}
