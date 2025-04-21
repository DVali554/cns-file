#include <stdio.h>
#include <string.h>
void vulnerableFunction(char* input) {
char buffer[10];
strcpy(buffer, input);
printf("Buffer contents: %s\n", buffer);
}
int main() {
char input[20];
printf("Enter input: ");
fgets(input, sizeof(input), stdin);
vulnerableFunction(input); return
0;
}
