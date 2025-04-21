#include <stdio.h>
#include <string.h>
int key[2][2] = {{5, 17}, {8, 3}};  // Hill cipher key matrix
int mod26(int x) { return (x % 26 + 26) % 26; } 

void hillEncrypt(char msg[]) {
    int a = msg[0] - 'A'; 
    int b = msg[1] - 'A';  
    int x = mod26(key[0][0] * a + key[0][1] * b);  
    int y = mod26(key[1][0] * a + key[1][1] * b); 
    printf("Encrypted: %c%c\n", x + 'A', y + 'A');  
}

int main() {
    char msg[3];  // Message input of length 2 + null terminator
    printf("Enter 2-letter UPPERCASE message: ");
    fgets(msg, sizeof(msg), stdin); 
    msg[strcspn(msg, "\n")] = '\0';  
    hillEncrypt(msg);  // Encrypt the message
    return 0;
}
