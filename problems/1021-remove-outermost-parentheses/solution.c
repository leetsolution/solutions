char* removeOuterParentheses(char* s) {
    int balance = 0;
    int start = 0;
    int len = 0;
    char* result = (char*)malloc(sizeof(char) * (strlen(s) + 1));
    int resultIndex = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            balance++;
            if (balance > 1) {
                result[resultIndex++] = s[i];
            }
        } else {
            balance--;
            if (balance > 0) {
                result[resultIndex++] = s[i];
            }
        }
    }
    
    result[resultIndex] = '\0';
    return result;
}