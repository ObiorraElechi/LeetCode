#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void expandAroundCenter (int* left, int* right, char* s, int stringLength){
    //expand from centre of given character, so long as palindrome is valid.
    while (*left >= 0 && *right < stringLength && s[*left] == s[*right]) {
        (*left)--;
        (*right)++;
    }

    // adjust left and right to the last valid palindrome boundary;
    (*left)++;
    (*right)--;

    return;
} 

char* longestPalindrome(char* s) {
    int left, right, stringLength = strlen(s);
    if (stringLength <= 1) return strdup(s);

    int start = 0, end = 0;


    if (s[0] == '\0') {
        return NULL;
    }

    for (int i = 0; i < stringLength; i++){

        int l1, l2, r1, r2;
        l1 = l2 = r1 = i;
        r2 = i + 1;
        expandAroundCenter(&l1, &r1, s, stringLength); //odd expansion
        expandAroundCenter(&l2, &r2, s, stringLength); //even expansion

        int currentLength = end - start;

        if (r1 - l1 > currentLength){
            start = l1;
            end = r1;
        }
        
        if (r2 - l2 > currentLength) {
            start = l2;
            end = r2;
        }
        
        
    }

    int len = end - start + 1;
    char* result = (char*)malloc(len + 1);
    if (!result) {
        exit(EXIT_FAILURE);
    }

    strncpy(result, s + start, len);
    result[len] = '\0';
    return result;
}

