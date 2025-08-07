char* makeGood(char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    if (len == 0) {
        return "";
    }

    char *stack = (char*)malloc((len + 1) * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++) {
        if (top == -1) {
            stack[++top] = s[i];
        } else {
            if (s[i] >= 'a' && s[i] <= 'z') {
                if (stack[top] == s[i] - 32) {
                    top--;
                } else {
                    stack[++top] = s[i];
                }
            } else {
                if (stack[top] == s[i] + 32) {
                    top--;
                } else {
                    stack[++top] = s[i];
                }
            }
        }
    }

    if (top == -1) {
        stack[0] = '\0';
    } else {
        stack[top + 1] = '\0';
    }

    char *result = (char*)malloc((top + 2) * sizeof(char));
    for (int i = 0; i <= top; i++) {
        result[i] = stack[i];
    }
    result[top + 1] = '\0';

    free(stack);

    return result;
}