#include <stdio.h>

// Function to perform a simple bit swap (for demonstration)
void simpleDES(int data, int key) {
    int left = data >> 4;    // Get the left 4 bits
    int right = data & 0x0F; // Get the right 4 bits

    // Simple XOR with key for encryption
    left = left ^ (key >> 4);  
    right = right ^ (key & 0x0F);

    // Combine the bits back
    int result = (left << 4) | right;
    printf("Encrypted Data: %X\n", result);  // Print result in hexadecimal
}

int main() {
    int data, key;
    printf("Enter 8-bit data (in hex, e.g., 0xA3): ");
    scanf("%X", &data);  // Input in hex
    printf("Enter 8-bit key (in hex, e.g., 0x1F): ");
    scanf("%X", &key);   // Input in hex

    simpleDES(data, key);  // Perform encryption using simplified DES
    return 0;
}
