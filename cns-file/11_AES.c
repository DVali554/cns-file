#include <stdio.h>

// Simple XOR encryption to demonstrate the concept of AES-like operation
void simpleAES(int data[4], int key[4]) {
    for (int i = 0; i < 4; i++) {
        data[i] ^= key[i];  // XOR each byte with the corresponding key byte
    }

    // Print encrypted data
    printf("Encrypted Data: ");
    for (int i = 0; i < 4; i++) {
        printf("%X ", data[i]);  // Print each byte in hex
    }
    printf("\n");
}

int main() {
    int data[4] = {0x32, 0x43, 0xF6, 0xA8};  // Example 4-byte data
    int key[4] = {0x2B, 0x7E, 0x15, 0x16};   // Example 4-byte key

    printf("Original Data: ");
    for (int i = 0; i < 4; i++) {
        printf("%X ", data[i]);
    }
    printf("\n");

    simpleAES(data, key);  // Perform simple "encryption"
    
    return 0;
}
