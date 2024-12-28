#include <stdlib.h> 
#include <stdio.h>
#define ASCII_CHAR_SET 256


int lengthOfLongestSubstring(char* s) {

    int lastSeen[ASCII_CHAR_SET];
    for (int i = 0; i < ASCII_CHAR_SET; i++) lastSeen[i] = -1;
    int largestLength = 0;
    int start = 0;

    for (int end = 0; s[end] != '\0'; end++) {
        if (lastSeen[s[end]] >= start) {
            start = lastSeen[s[end]] + 1;
        }
        

        lastSeen[s[end]] = end;

        int currentLength = end - start + 1;
        if (currentLength > largestLength) largestLength = currentLength;

    }

    return largestLength;
}

