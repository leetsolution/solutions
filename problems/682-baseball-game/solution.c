int calPoints(char** operations, int operationsSize) {
    int stack[1000];
    int top = -1;
    int sum = 0;
    for (int i = 0; i < operationsSize; i++) {
        if (strcmp(operations[i], "+") == 0) {
            int a = stack[top];
            int b = stack[top - 1];
            int c = a + b;
            stack[++top] = c;
        } else if (strcmp(operations[i], "D") == 0) {
            int a = stack[top] * 2;
            stack[++top] = a;
        } else if (strcmp(operations[i], "C") == 0) {
            top--;
        } else {
            int num = atoi(operations[i]);
            stack[++top] = num;
        }
    }
    for (int i = 0; i <= top; i++) {
        sum += stack[i];
    }
    return sum;
}