#include <stdlib.h>
#include <stdio.h>

/**
 * 1. Two Sum Problem 
 * 
 * Note: The returned array must be malloced, assume caller calls free().
 * 
 * Obi Note: Did this quickly before work, will implement hash map to achieve O(n) time complexity.
 */

#define HASH_SIZE 200003

typedef struct node{
    int key;
    int value;
    struct node *next;
} node_t;

typedef struct{
    node_t** buckets;
    int size;    
} hashMap_t;

hashMap_t* createHashMap(int size){
    hashMap_t* map = (hashMap_t *)malloc(sizeof(hashMap_t));
    if (map == NULL) exit(EXIT_FAILURE);
    map->size = size;
    map->buckets = (node_t**)calloc(size, sizeof(node_t*));
    if (map->buckets == NULL) exit(EXIT_FAILURE);
    return map;
}

int hashFunction(int key, int size){
    return((key % size) + size ) % size;
}


void insert(hashMap_t* map, int key, int value) {
    int index = hashFunction(key, map->size);
    node_t* newNode = ((node_t*)malloc(sizeof(node_t)));
    if (newNode == NULL) exit(EXIT_FAILURE);
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
}   

int search(hashMap_t* map, int key) {
    int index = hashFunction(key, map->size);
    node_t* currentNode = map->buckets[index];
    while(currentNode) {
        if (currentNode->key == key) {
            return currentNode->value;
        }
        currentNode = currentNode->next;
    }
    return -1; // key not found
}


void freeHashMap(hashMap_t *map) {
    for (int i = 0; i < map->size; i++) {
        node_t* currentNode = map->buckets[i];
        while(currentNode) {
            node_t *tempNode = currentNode;
            currentNode = currentNode->next;
            free(tempNode);
        }
    }
    free(map->buckets);
    free(map);
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    hashMap_t *map = createHashMap(HASH_SIZE);
    int *result = (int*)malloc(2 * sizeof(int));
    if (result == NULL) exit(EXIT_FAILURE);
    
    for (int i = 0; i < numsSize; i++) {
            int complement = target - nums[i];
            int complementIndex = search(map, complement);
            if (complementIndex != -1) {
                result[0] =complementIndex;
                result[1] = i;
                *returnSize = 2;
                freeHashMap(map);
                return result;
            }
        
        insert(map, nums[i], i);
    }

    *returnSize = 0;
    free(result);
    freeHashMap(map);
    return NULL;
    
}