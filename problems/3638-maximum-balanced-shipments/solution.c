int maxBalancedShipments(int* weight, int weightSize) {
    #include <stdio.h>
    #include <stdlib.h>
    #include <limits.h>

    int maxBalancedShipments(int* weight, int weightSize){
        int count = 0;
        int i = 0;
        while (i < weightSize) {
            int max_weight = INT_MIN;
            int j = i;
            while (j < weightSize) {
                max_weight = (weight[j] > max_weight) ? weight[j] : max_weight;
                if (j == weightSize -1 || weight[j+1] > max_weight)
                {
                    if (weight[j] < max_weight){
                        count++;
                        i = j + 1;
                        break;
                    } else {
                        i = j + 1;
                        break;
                    }
                }
                j++;
            }
            if (j == weightSize) break;
        }
        return count;
    }
}