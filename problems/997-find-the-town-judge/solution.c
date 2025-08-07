int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int *trusts = (int *)calloc(n + 1, sizeof(int));
    int *trustedBy = (int *)calloc(n + 1, sizeof(int));
    if (trusts == NULL || trustedBy == NULL) {
        return -1;
    }
    for (int i = 0; i < trustSize; i++) {
        trusts[trust[i][0]]++;
        trustedBy[trust[i][1]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (trusts[i] == 0 && trustedBy[i] == n - 1) {
            free(trusts);
            free(trustedBy);
            return i;
        }
    }
    free(trusts);
    free(trustedBy);
    return -1;
}