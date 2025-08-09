/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;
    char **result = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        int num = i + 1;
        if (num % 15 == 0) {
            result[i] = (char *)malloc(9 * sizeof(char));
            strcpy(result[i], "FizzBuzz");
        } else if (num % 3 == 0) {
            result[i] = (char *)malloc(5 * sizeof(char));
            strcpy(result[i], "Fizz");
        } else if (num % 5 == 0) {
            result[i] = (char *)malloc(5 * sizeof(char));
            strcpy(result[i], "Buzz");
        } else {
            result[i] = (char *)malloc(12 * sizeof(char)); 
            sprintf(result[i], "%d", num);
        }
    }
    return result;
}