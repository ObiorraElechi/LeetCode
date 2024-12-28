/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *dummyHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (dummyHead == NULL) exit(EXIT_FAILURE);
    struct ListNode *currentNode = dummyHead;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry > 0){
    int val1 = (l1 != NULL) ? l1->val : 0; // use zero if l1 == NULL
    int val2 = (l2 != NULL) ? l2->val : 0; //use zero if l2 == NULL

        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;


        currentNode->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (currentNode->next == NULL) exit(EXIT_FAILURE);
        
        currentNode = currentNode->next;
        currentNode->val = sum;
        currentNode->next = NULL;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    struct ListNode* sum = dummyHead->next;
    free(dummyHead);
    return sum;
}