/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {
    int min_sum = INT_MAX;
    int count = 0;
    char ***res = (char ***)malloc(sizeof(char **) * 1000);
    for (int i = 0; i < list1Size; i++) {
        for (int j = 0; j < list2Size; j++) {
            if (strcmp(list1[i], list2[j]) == 0) {
                if (i + j < min_sum) {
                    min_sum = i + j;
                    count = 0;
                    res[count++] = &list1[i];

                } else if (i + j == min_sum) {
                    res[count++] = &list1[i];
                }
            }
        }
    }
    char **result = (char **)malloc(sizeof(char *) * count);
    *returnSize = count;
    for (int i = 0; i < count; i++) {
        result[i] = strdup(res[i][0]);
    }
    return result;
}