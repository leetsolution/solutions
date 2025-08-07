#include <stdio.h>
#include <stdlib.h>

int distinctAverages(int* nums, int numsSize) {
    if (numsSize <= 0) {
        return 0;
    }

    int distinct_count = 0;
    double averages[50] = {0.0};
    int averages_size = 0;

    // Sort the array
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        double average = (double)(nums[left] + nums[right]) / 2.0;
        int found = 0;
        for (int i = 0; i < averages_size; i++) {
            if (averages[i] == average) {
                found = 1;
                break;
            }
        }
        if (!found) {
            averages[averages_size++] = average;
            distinct_count++;
        }
        left++;
        right--;
    }

    return distinct_count;
}