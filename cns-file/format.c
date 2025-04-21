#include <stdio.h>
int main() {
char secret[] = "Sensitive Data";
char input[10];
printf("Enter your name: ");
fgets(input, sizeof(input), stdin);
printf(input);
printf("Welcome, %s!\n", input);
printf("The secret is: %s\n", secret);
return 0;
}