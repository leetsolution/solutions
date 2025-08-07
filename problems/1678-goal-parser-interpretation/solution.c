char * interpret(char * command){
    int len = 0;
    for(int i = 0; command[i] != '\0'; i++){
        len++;
    }
    char *result = (char*)malloc(sizeof(char) * (2 * len + 1));
    int resultIndex = 0;
    for(int i = 0; i < len; i++){
        if(command[i] == 'G'){
            result[resultIndex++] = 'G';
        } else if(command[i] == '('){
            if(command[i+1] == ')'){
                result[resultIndex++] = 'o';
                i++;
            } else {
                result[resultIndex++] = 'a';
                result[resultIndex++] = 'l';
                i += 3;
            }
        }
    }
    result[resultIndex] = '\0';
    return result;
}