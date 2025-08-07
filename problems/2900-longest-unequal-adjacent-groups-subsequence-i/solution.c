/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** getLongestSubsequence(char** words, int wordsSize, int* groups, int groupsSize, int* returnSize) {
    char** result = (char**)malloc(sizeof(char*) * wordsSize);
    int count = 0;
    int lastGroup = -1;
    
    for (int i = 0; i < wordsSize; i++) {
        if (groups[i] != lastGroup) {
            result[count] = words[i];
            count++;
            lastGroup = groups[i];
        }
    }
    
    *returnSize = count;
    return result;
}