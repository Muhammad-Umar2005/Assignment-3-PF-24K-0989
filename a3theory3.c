#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int main() {
    char* email=(char*) malloc(sizeof(char)*100);
    printf("Enter an email address: ");
    fgets(email, sizeof(email), stdin);

    size_t len = strlen(email);
    if (len > 0 && email[len - 1] == '\n') {
        email[len - 1] = '\0';
    }

    int isValid = 1; // Assume email is valid initially

    if (strlen(email) == 0) {
        isValid = 0;
    } else {
        char* atSymbol = strchr(email, '@');
        if (atSymbol == NULL) {
            isValid = 0;
        } else {
            if (strchr(atSymbol + 1, '@') != NULL) {
                isValid = 0;
            }
            if (strchr(atSymbol + 1, '.') == NULL) {
                isValid = 0; 
            }

        }

    }
    if (isValid) {
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }
free(email);
    return 0;
}
