#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int k;
    int* nums;
    int size;
    int capacity;
} KthLargest;


KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->k = k;
    obj->size = numsSize;
    obj->capacity = k;
    obj->nums = (int*)malloc(sizeof(int) * k);

    if (numsSize >= k) {
        for (int i = 0; i < k; i++) {
            obj->nums[i] = nums[i];
        }
    } else {
        for (int i = 0; i < numsSize; i++) {
            obj->nums[i] = nums[i];
        }
    }

    for (int i = 0; i < obj->size; i++) {
        for (int j = i; j > 0; j--) {
            if (obj->nums[j] > obj->nums[j - 1]) {
                int temp = obj->nums[j];
                obj->nums[j] = obj->nums[j - 1];
                obj->nums[j - 1] = temp;
            }
        }
    }
    
    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->k) {
        obj->nums[obj->size] = val;
        obj->size++;
    
        for (int i = 0; i < obj->size; i++) {
            for (int j = i; j > 0; j--) {
                if (obj->nums[j] > obj->nums[j - 1]) {
                    int temp = obj->nums[j];
                    obj->nums[j] = obj->nums[j - 1];
                    obj->nums[j - 1] = temp;
                }
            }
        }
        return obj->nums[obj->k - 1];
    } else {
        if (val > obj->nums[obj->k - 1]) {
            obj->nums[obj->k - 1] = val;
            for (int i = 0; i < obj->k; i++) {
                for (int j = i; j > 0; j--) {
                    if (obj->nums[j] > obj->nums[j - 1]) {
                        int temp = obj->nums[j];
                        obj->nums[j] = obj->nums[j - 1];
                        obj->nums[j - 1] = temp;
                    }
                }
            }
        }
    }
    return obj->nums[obj->k - 1];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->nums);
    free(obj);
}