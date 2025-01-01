#include <math.h>
#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // assign variables where A and m refer to the smaller array
    int *A = (nums1Size <= nums2Size) ? nums1 : nums2;
    int *B = (nums1Size <= nums2Size) ? nums2 : nums1;
    int m = (nums1Size <= nums2Size) ? nums1Size : nums2Size;
    int n = (nums1Size <= nums2Size) ? nums2Size : nums1Size;

    int total = m + n;
    int half = total / 2;


    int l = 0, r = m;
    while (l <= r) {
        int i = (l + r) / 2; // partition index for A
        int j = half - i;    // partition index for B

        // edge cases for out of bounds elements
        int ALeft = (i > 0) ? A[i - 1] : INT_MIN;
        int ARight = (i < m) ? A[i] : INT_MAX;

        int BLeft = (j > 0) ? B[j - 1] : INT_MIN;
        int BRight = (j < n) ? B[j] : INT_MAX;

        // valid partition conditions
        if (ALeft <= BRight && BLeft <= ARight) {
            // found the correct partition
            if (total % 2 == 1) {
                return fmin(ARight, BRight); 
            } else {
                return (fmax(ALeft, BLeft) + fmin(ARight, BRight)) / 2.0; 
            }
        } else if (ALeft > BRight) {
            // move left in A
            r = i - 1;
        } else {
            // move right in A
            l = i + 1;
        }
    }

    return 0.0;
}
