char* resultingString(char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    if (len < 2) {
        return s;
    }

    char* stack = (char*)malloc((len + 1) * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++) {
        if (top == -1) {
            stack[++top] = s[i];
        } else {
            char topChar = stack[top];
            char currentChar = s[i];

            if ((topChar == 'a' && currentChar == 'z') || (topChar == 'z' && currentChar == 'a') ||
                (topChar + 1 == currentChar) || (topChar - 1 == currentChar)) {
                top--;
            } else {
                stack[++top] = s[i];
            }
        }
    }

    stack[top + 1] = '\0';

    if (top == -1) {
        s[0] = '\0';
        free(stack);
        return s;
    }
    
    for(int i = 0; i <= top; i++){
        s[i] = stack[i];
    }
    s[top+1] = '\0';
    free(stack);
    return s;
}