/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minCosts(int* cost, int costSize, int* returnSize) {
    int* answer = (int*)malloc(costSize * sizeof(int));
    *returnSize = costSize;

    if (costSize == 0) {
        return answer;
    }

    int min_cost = cost[0];
    answer[0] = cost[0];

    for (int i = 1; i < costSize; i++) {
        if (cost[i] < min_cost) {
            min_cost = cost[i];
        }
        answer[i] = min_cost;
    }

    return answer;
}