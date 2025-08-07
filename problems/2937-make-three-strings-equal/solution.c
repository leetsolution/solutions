int findMinimumOperations(char* s1, char* s2, char* s3) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);
    int i = len1 - 1, j = len2 - 1, k = len3 - 1;
    int operations = 0;
    while (i >= 0 && j >= 0 && k >= 0) {
        if (s1[i] == s2[j] && s2[j] == s3[k]) {
            i--;
            j--;
            k--;
        } else {
            if (i == j && j ==k) return -1;
            if (i > j || i > k) i--;
            else if (j > i || j > k) j--;
            else k--;
            operations++;
        }
    }
    if (i >= 0 || j >= 0 || k >= 0) return -1;
    return operations;
}