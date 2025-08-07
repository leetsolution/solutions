/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

typedef struct {
    int val;
    int freq;
} NumFreq;

int compare(const void *a, const void *b) {
    NumFreq *nf1 = (NumFreq *)a;
    NumFreq *nf2 = (NumFreq *)b;

    if (nf1->freq != nf2->freq) {
        return nf1->freq - nf2->freq;
    } else {
        return nf2->val - nf1->val;
    }
}

int* frequencySort(int* nums, int numsSize, int* returnSize) {
    int *result = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    NumFreq freqMap[201] = {0};
    for (int i = 0; i < 201; i++) {
        freqMap[i].val = i - 100;
        freqMap[i].freq = 0;
    }

    for (int i = 0; i < numsSize; i++) {
        freqMap[nums[i] + 100].freq++;
    }

    NumFreq numFreqArray[numsSize];
    int numFreqSize = 0;
    for (int i = 0; i < 201; i++) {
        if (freqMap[i].freq > 0) {
            numFreqArray[numFreqSize].val = freqMap[i].val;
            numFreqArray[numFreqSize].freq = freqMap[i].freq;
            numFreqSize++;
        }
    }

    qsort(numFreqArray, numFreqSize, sizeof(NumFreq), compare);

    int index = 0;
    for (int i = 0; i < numFreqSize; i++) {
        for (int j = 0; j < numFreqArray[i].freq; j++) {
            result[index++] = numFreqArray[i].val;
        }
    }

    return result;
}