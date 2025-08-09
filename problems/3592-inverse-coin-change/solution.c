/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findCoins(int* numWays, int numWaysSize, int* returnSize) {
    int* result = (int*)malloc(numWaysSize * sizeof(int));
    int resultIndex = 0;
    
    for (int i = 1; i <= numWaysSize; i++) {
        if (i == 1) {
            if (numWays[1] != 1) {
                *returnSize = 0;
                return (int*)malloc(0);
            }
            result[resultIndex++] = 1;
        } else if (numWays[i] > 0) {
            
            int tempWays[101] = {0};
            tempWays[0] = 1;

            for(int coin = 0; coin < resultIndex; coin++) {
                for(int amount = result[coin]; amount <= i; amount++) {
                    tempWays[amount] += tempWays[amount - result[coin]];
                }
            }
            
            int foundNewCoin = 0;
            if (tempWays[i] == 0 && numWays[i] == 1) {
                foundNewCoin = 1;
            }
            
            if(numWays[i] - tempWays[i] > 0) {
                int currentWays = tempWays[i];
                tempWays[0] = 1;

                for(int coin = 0; coin < resultIndex; coin++) {
                    for(int amount = result[coin]; amount <= i; amount++) {
                        tempWays[amount] = tempWays[amount-result[coin]] + tempWays[amount];
                    }
                }
                if (numWays[i] != tempWays[i])
                {
                    result[resultIndex++] = i;
                }
                else if(numWays[i] > tempWays[i]){
                     result[resultIndex++] = i;
                 }
            }
            
            if (numWays[i] == 1 && foundNewCoin == 1)
            {
                
                result[resultIndex++] = i;
                
            }
            
           
        }
    }
    
    if (resultIndex == 0) {
        *returnSize = 0;
        return (int*)malloc(0);
    }
    
    int* finalResult = (int*)malloc(resultIndex * sizeof(int));
    for (int i = 0; i < resultIndex; i++) {
        finalResult[i] = result[i];
    }
    
    
    for (int i = 0; i < resultIndex - 1; i++) {
        for (int j = i + 1; j < resultIndex; j++) {
            if (finalResult[i] > finalResult[j]) {
                int temp = finalResult[i];
                finalResult[i] = finalResult[j];
                finalResult[j] = temp;
            }
        }
    }
    
    *returnSize = resultIndex;
    return finalResult;
}