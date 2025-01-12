#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int reverse(int x){
    int size = snprintf(NULL, 0, "%d", x) + 1;
    
    if (size > INT_MAX || size < 0) return 0;
    
    char* strArray = (char*) malloc(sizeof(char)*size);
    
    if (strArray == NULL) {
        perror("memory allocation failed");
        exit(EXIT_FAILURE);
    }
    
    sprintf(strArray, "%d", x);

    int p1 = (x < 0) ? 1 : 0; 
    int p2 = strlen(strArray) - 1;
    
    while (p1 < p2) {
        char temp = strArray[p1];
        strArray[p1] = strArray[p2];
        strArray[p2] = temp;
        p1++;
        p2--;
    }


    long long reversedInt;

    sscanf(strArray, "%lld", &reversedInt);
    free(strArray);
    
    if (reversedInt < INT_MIN || reversedInt > INT_MAX) return 0;
    return (int) reversedInt;
}