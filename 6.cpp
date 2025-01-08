#include <string.h>
#include <iostream>
#include <vector>

class Solution {
    public:
    std::string convert(std::string s, int numRows) {

        if (numRows == 1) return s; //no zig zag pattern can be applied to a string if there is only one row.

        std::vector<std::string> rows(numRows);

        int i {0}, step {1};

        for (char c: s) {
            rows[i] += c;

            if (i == 0) step = 1;
            if (i == numRows - 1) step = -1;

            i += step;

        }
        

        std::string result = ""; //initalising empty string which we will store vecore chars into. 
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
        
    }
}; 