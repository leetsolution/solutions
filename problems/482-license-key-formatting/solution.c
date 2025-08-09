char* licenseKeyFormatting(char* s, int k) {
    int n = strlen(s);
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != '-') {
            count++;
        }
    }
    int groups = (count + k - 1) / k;
    int resultSize = count + groups -1;
    char* result = (char*)malloc((resultSize + 1) * sizeof(char));
    int index = 0;
    int groupCount = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != '-') {
            if (groupCount == k) {
                result[index++] = '-';
                groupCount = 0;
            }
            result[index++] = toupper(s[i]);
            groupCount++;
        }
    }
    result[resultSize] = '\0';
    int left = 0;
    int right = resultSize - 1;
    while (left < right) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
        left++;
        right--;
    }
    return result;
}