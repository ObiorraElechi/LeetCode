#include <stdlib.h>

/**
 * 1. Two Sum Problem 
 * 
 * Note: The returned array must be malloced, assume caller calls free().
 * 
 * Obi Note: Did this quickly before work, will implement hash map to achieve O(n) time complexity.
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    int* twoSumArray = (int *) malloc(2 *sizeof(int));
    if (twoSumArray == NULL){
        *returnSize = 0;
        return NULL;
    } 

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j ++) {
            if (nums[i] + nums[j] == target){
                twoSumArray[0] = i;
                twoSumArray[1] = j;
                *returnSize = 2;

                return twoSumArray;
            } 
        }
    }

    *returnSize = 0;
    free(twoSumArray);
    return NULL;

}