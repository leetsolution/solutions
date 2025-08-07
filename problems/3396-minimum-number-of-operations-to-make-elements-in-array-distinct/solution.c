int minimumOperations(int* nums, int numsSize) {
    int operations = 0;
    int i;
    while (1) {
        int distinct = 1;
        for (i = 0; i < numsSize; i++) {
            for (int j = i + 1; j < numsSize; j++) {
                if (nums[i] == nums[j]) {
                    distinct = 0;
                    break;
                }
            }
            if (!distinct) break;
        }

        if (distinct) {
            return operations;
        }

        if (numsSize == 0) return operations;
        
        operations++;
        numsSize -= 3;
        if(numsSize < 0) numsSize = 0;
    }
}