int findLUSlength(char* a, char* b) {
    if (strcmp(a, b) == 0) {
        return -1;
    } else {
        return max(strlen(a), strlen(b));
    }
}