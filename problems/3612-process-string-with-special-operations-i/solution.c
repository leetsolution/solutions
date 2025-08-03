char* processStr(char* s) {
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    char * processString(char * s){
        char *result = (char *)malloc(sizeof(char));
        result[0] = '\0';
        int resultLen = 0;
        int sLen = strlen(s);

        for(int i = 0; i < sLen; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                result = (char *)realloc(result, (resultLen + 2) * sizeof(char));
                result[resultLen++] = s[i];
                result[resultLen] = '\0';
            } else if (s[i] == '*'){
                if(resultLen > 0){
                    result = (char *)realloc(result, (resultLen) * sizeof(char));
                    result[--resultLen] = '\0';
                }
            } else if (s[i] == '#'){
                result = (char *)realloc(result, (resultLen * 2 + 1) * sizeof(char));
                strcat(result, result);
                resultLen *= 2;
            } else if (s[i] == '%'){
                int left = 0;
                int right = resultLen -1;
                while(left < right){
                    char temp = result[left];
                    result[left] = result[right];
                    result[right] = temp;
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
}