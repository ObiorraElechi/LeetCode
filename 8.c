#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int myAtoi(char* s) {

    int currIndex = 0, sign = 1;
    long result = 0;

    //skips white spaces
    while (s[currIndex] == ' '){
        currIndex++;
    }

    //determines sinage
    sign = (s[currIndex] == '-') ? -1 : 1;
    if (s[currIndex] == '-' || s[currIndex] == '+') currIndex++;

    //appends char to result given it correctly passes conditions
    while (s[currIndex] >= '0' && s[currIndex] <= '9') {
        int digit = s[currIndex] - '0';

        if (result > (LONG_MAX - digit) / 10) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        currIndex++;
    }

    result *= sign;

    if (result < INT_MIN) return INT_MIN;
    if (result > INT_MAX) return INT_MAX;
    return (int) result;
}
