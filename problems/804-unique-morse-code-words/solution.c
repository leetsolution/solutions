#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int uniqueMorseRepresentations(char** words, int wordsSize) {
    char* morse[] = {".-","-...","-.-.","-..",".","..-.","--.",
                      "....","..",".---","-.-",".-..","--","-.",
                      "---",".--.","--.-",".-.","...","-","..-",
                      "...-",".--","-..-","-.--","--.."};
    char* transformations[wordsSize];
    int count = 0;
    int unique_count = 0;
    for(int i = 0; i < wordsSize; i++){
        char transformation[100] = "";
        for(int j = 0; j < strlen(words[i]); j++){
            strcat(transformation, morse[words[i][j] - 'a']);
        }
        int found = 0;
        for(int k = 0; k < count; k++){
            if(strcmp(transformations[k], transformation) == 0){
                found = 1;
                break;
            }
        }
        if(found == 0){
            transformations[count] = (char*)malloc(strlen(transformation) + 1);
            strcpy(transformations[count], transformation);
            count++;
            unique_count++;
        }
    }
    for(int i = 0; i < count; i++){
        free(transformations[i]);
    }
    return unique_count;
}