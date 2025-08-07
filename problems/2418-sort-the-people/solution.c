/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    int i, j;
    char** result = (char**)malloc(sizeof(char*) * namesSize);
    int* indices = (int*)malloc(sizeof(int) * namesSize);

    for (i = 0; i < namesSize; i++) {
        indices[i] = i;
    }

    for (i = 0; i < namesSize - 1; i++) {
        for (j = 0; j < namesSize - i - 1; j++) {
            if (heights[indices[j]] < heights[indices[j + 1]]) {
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < namesSize; i++) {
        result[i] = names[indices[i]];
    }

    *returnSize = namesSize;
    free(indices);
    return result;
}