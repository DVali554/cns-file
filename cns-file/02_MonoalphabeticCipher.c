#include <stdio.h>
#include <string.h>

char key[27] = "QWERTYUIOPASDFGHJKLZXCVBNM";  // Note: 27 for null terminator

void monoEncrypt(char *msg) {
    int i;
    for (i = 0; msg[i]; i++) {
        if (msg[i] >= 'A' && msg[i] <= 'Z')
            msg[i] = key[msg[i] - 'A'];
        else if (msg[i] >= 'a' && msg[i] <= 'z')
            msg[i] = key[msg[i] - 'a'] + 32;  // Convert mapped uppercase to lowercase
    }
}

int main() {
    char msg[100];
    printf("Enter message: ");
    fgets(msg, sizeof(msg), stdin);
    msg[strcspn(msg, "\n")] = '\0';  // Remove newline character
    monoEncrypt(msg);
    printf("Encrypted: %s\n", msg);
    return 0;
}
