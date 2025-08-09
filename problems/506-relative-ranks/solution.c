/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    int i, j;
    int *index = (int *)malloc(sizeof(int) * scoreSize);
    int *sorted_score = (int *)malloc(sizeof(int) * scoreSize);
    char **rank = (char **)malloc(sizeof(char *) * scoreSize);
    for (i = 0; i < scoreSize; i++) {
        index[i] = i;
        sorted_score[i] = score[i];
    }
    qsort(sorted_score, scoreSize, sizeof(int),
          (int (*)(const void *, const void *))greater);
    for (i = 0; i < scoreSize; i++) {
        rank[i] = (char *)malloc(sizeof(char) * 10);
    }
    for (i = 0; i < scoreSize; i++) {
        for (j = 0; j < scoreSize; j++) {
            if (score[i] == sorted_score[j]) {
                if (j == 0) {
                    strcpy(rank[i], "Gold Medal");
                } else if (j == 1) {
                    strcpy(rank[i], "Silver Medal");
                } else if (j == 2) {
                    strcpy(rank[i], "Bronze Medal");
                } else {
                    sprintf(rank[i], "%d", j + 1);
                }
                break;
            }
        }
    }
    *returnSize = scoreSize;
    free(index);
    free(sorted_score);
    return rank;
}