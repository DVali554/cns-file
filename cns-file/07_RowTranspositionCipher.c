#include <stdio.h>
#include <string.h>

void rowTranspositionEncrypt(char *msg, int key[]) {
    int len = strlen(msg), rows = (len + 2) / 3;
    char grid[rows][3];
    int k = 0;
    
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < 3; j++)
            grid[i][j] = (k < len) ? msg[k++] : 'X';
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < rows; j++)
            printf("%c", grid[j][key[i] - 1]);
    printf("\n");
}

int main() {
    char msg[100];
    int key[] = {3, 1, 2};
    printf("Enter message: ");
    fgets(msg, sizeof(msg), stdin);
    msg[strcspn(msg, "\n")] = '\0';  // Remove newline character
    rowTranspositionEncrypt(msg, key);
    return 0;
}
