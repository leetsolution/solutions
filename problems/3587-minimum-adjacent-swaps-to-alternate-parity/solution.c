int minSwaps(int* nums, int numsSize) {
    int evenCount = 0;
    int oddCount = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }
    
    if (abs(evenCount - oddCount) > 1) {
        return -1;
    }
    
    long long swaps1 = 0;
    long long swaps2 = 0;
    
    if (evenCount >= oddCount) {
        int evenPos = 0;
        for (int i = 0; i < numsSize; i++) {
            if (i % 2 == 0) {
                if (nums[i] % 2 != 0) {
                    int j = i + 1;
                    while (j < numsSize && nums[j] % 2 != 0) {
                        j++;
                    }
                    if (j < numsSize) {
                        for (int k = j; k > i; k--) {
                           
                        }
                        int temp = nums[j];
                        for(int k = j; k > i; k--){
                            nums[k] = nums[k-1];
                        }
                        nums[i] = temp;

                         for(int k = i + 1; k <= j; k++){
                            swaps1++;
                        }
                    }
                    
                }
                
            }
        }
       
       
        int tempArr[numsSize];
        for(int i=0; i<numsSize; i++) tempArr[i] = nums[i];
    
    
         for(int i=0; i<numsSize; i++) nums[i] = tempArr[i];
        

    }
    
    if (oddCount >= evenCount) {
       int oddPos = 0;
        for (int i = 0; i < numsSize; i++) {
            if (i % 2 == 0) {
                if (nums[i] % 2 == 0) {
                    int j = i + 1;
                    while (j < numsSize && nums[j] % 2 == 0) {
                        j++;
                    }
                    if (j < numsSize) {
                        for (int k = j; k > i; k--) {
                            
                        }

                        int temp = nums[j];
                        for(int k = j; k > i; k--){
                            nums[k] = nums[k-1];
                        }
                        nums[i] = temp;
                         for(int k = i + 1; k <= j; k++){
                            swaps2++;
                        }
                    }
                }
            }
        }
    }

    if (evenCount > oddCount) {
         int evenPos = 0;

        int tempArr[numsSize];
        for(int i=0; i<numsSize; i++) tempArr[i] = nums[i];
        long long tempSwaps = 0;


         for (int i = 0; i < numsSize; i++) {
            if (i % 2 == 0) {
                if (tempArr[i] % 2 != 0) {
                    int j = i + 1;
                    while (j < numsSize && tempArr[j] % 2 != 0) {
                        j++;
                    }
                    if (j < numsSize) {
                         for (int k = j; k > i; k--) {
                           
                        }
                        int temp = tempArr[j];
                        for(int k = j; k > i; k--){
                            tempArr[k] = tempArr[k-1];
                        }
                        tempArr[i] = temp;

                         for(int k = i + 1; k <= j; k++){
                            tempSwaps++;
                        }
                    }
                    else {
                        tempSwaps = 10000000000000;
                        break;
                    }
                    
                }
                
            }
        }

        return (swaps1 <= tempSwaps) ? swaps1:tempSwaps;
    }
    
    
    if (oddCount > evenCount) return swaps2;

    if(oddCount == evenCount){
        int evenPos = 0;

        int tempArr[numsSize];
        for(int i=0; i<numsSize; i++) tempArr[i] = nums[i];
        long long tempSwaps = 0;

         for (int i = 0; i < numsSize; i++) {
            if (i % 2 == 0) {
                if (tempArr[i] % 2 != 0) {
                    int j = i + 1;
                    while (j < numsSize && tempArr[j] % 2 != 0) {
                        j++;
                    }
                    if (j < numsSize) {
                         for (int k = j; k > i; k--) {
                           
                        }
                        int temp = tempArr[j];
                        for(int k = j; k > i; k--){
                            tempArr[k] = tempArr[k-1];
                        }
                        tempArr[i] = temp;

                         for(int k = i + 1; k <= j; k++){
                            tempSwaps++;
                        }
                    }
                    else {
                        tempSwaps = 10000000000000;
                        break;
                    }
                    
                }
                
            }
        }
      return (swaps2 <= tempSwaps) ? swaps2:tempSwaps;
    }
     return 0;
}