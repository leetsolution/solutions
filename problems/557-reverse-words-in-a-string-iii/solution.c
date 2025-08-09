char* reverseWords(char* s) {
    int n = strlen(s);
    int start = 0;
    for (int i = 0; i <= n; i++) {
        if (i == n || s[i] == ' ') {
            int end = i - 1;
            while (start < end) {
                char temp = s[start];
                s[start] = s[end];
                s[end] = temp;
                start++;
                end--;
            }
            start = i + 1;
        }
    }
    return s;
}