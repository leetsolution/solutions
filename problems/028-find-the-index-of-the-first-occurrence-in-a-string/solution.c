int strStr(char* haystack, char* needle) {
    if (*needle == '\0') {
        return 0;
    }
    if (*haystack == '\0') {
        return -1;
    }

    int haystack_len = 0;
    while (haystack[haystack_len] != '\0') {
        haystack_len++;
    }

    int needle_len = 0;
    while (needle[needle_len] != '\0') {
        needle_len++;
    }

    if (needle_len > haystack_len) {
        return -1;
    }

    for (int i = 0; i <= haystack_len - needle_len; i++) {
        int j;
        for (j = 0; j < needle_len; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == needle_len) {
            return i;
        }
    }

    return -1;
}