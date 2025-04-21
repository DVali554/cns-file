#include <stdio.h>
#include <string.h>

void railFenceEncrypt(char *msg, int key) {
    int len = strlen(msg), row = 0, down = 0;
    char rail[key][len];
    memset(rail, '\0', sizeof(rail));

    for (int i = 0; i < len; i++) {
        rail[row][i] = msg[i];
        row = down ? row + 1 : row - 1;
        if (row == 0 || row == key - 1) down = !down;
    }

    for (int i = 0; i < key; i++) 
        for (int j = 0; j < len; j++) 
            if (rail[i][j]) printf("%c", rail[i][j]);
    printf("\n");
}

int main() {
    char msg[100];
    printf("Enter message: ");
    fgets(msg, 100, stdin);
    msg[strcspn(msg, "\n")] = 0;
    railFenceEncrypt(msg, 3);
    return 0;
}
