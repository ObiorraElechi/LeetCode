#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isPalindrome(int x) {
    int size = snprintf(NULL, 0, "%d", x) + 1; 

    char* palindromeArray = (char*)malloc(sizeof(char)*size);

    if (!palindromeArray) {
        perror("memory allocation failed");
        exit(EXIT_FAILURE);
    }

    sprintf(palindromeArray, "%d", x);

    int p1 = 0;
    int p2 = strlen(palindromeArray) - 1;

    while (p1 < p2) {
        if (palindromeArray[p1] != palindromeArray[p2]){
            free(palindromeArray);
            return false;
        }
        p1++;
        p2--;
    }
    free(palindromeArray);
    return true;
}