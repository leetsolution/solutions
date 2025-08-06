int maxBalancedShipments(int* weight, int weightSize) {
    #include <stdio.h>
    #include <stdlib.h>
    #include <limits.h>

    int maxBalancedShipments(int* weight, int weightSize){
        int count = 0;
        int i = 0;
        while (i < weightSize) {
            int maxWeight = INT_MIN;
            int j = i;
            while (j < weightSize) {
                maxWeight = (weight[j] > maxWeight) ? weight[j] : maxWeight;
                if (j == weightSize -1 || weight[j+1] > maxWeight) {
                    if (j > i && weight[j] < maxWeight) {
                        count++;
                        i = j + 1;
                        break;
                    } else {
                        i++;
                        break;
                    }
                }
                j++;
            }
            if (j == weightSize){
                break;
            }
        }
        return count;
    }
}