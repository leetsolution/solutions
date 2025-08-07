int minLength(char* s) {
    char stack[101];
    int top = -1;
    int i = 0;

    while (s[i] != '\0') {
        if (top >= 0 && ((stack[top] == 'A' && s[i] == 'B') || (stack[top] == 'C' && s[i] == 'D'))) {
            top--;
        } else {
            stack[++top] = s[i];
        }
        i++;
    }

    return top + 1;
}