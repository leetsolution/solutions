#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* toGoatLatin(char* sentence) {
    char *result = (char *)malloc(1000); 
    char *word = strtok(sentence, " ");
    int index = 1;
    int res_index = 0;
    while (word != NULL) {
        char firstChar = tolower(word[0]);
        char *newWord;
        if (firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u') {
            newWord = (char *)malloc(strlen(word) + 3 + index);
            strcpy(newWord, word);
            strcat(newWord, "ma");
        } else {
            newWord = (char *)malloc(strlen(word) + 3 + index);
            newWord[0] = word[1];
            newWord[strlen(word)] = '\0';
            strncpy(newWord + 1, word + 1, strlen(word) -1);
            strcat(newWord, word);
            strcat(newWord, "ma");
            newWord[strlen(newWord) -strlen(word)] = word[0];
        }

        for (int i = 0; i < index; i++) {
            strcat(newWord, "a");
        }
        
        strcat(result, newWord);
        if (word != strtok(NULL, " ")) {
            strcat(result, " ");
        }
        
        free(newWord);
        word = strtok(NULL, " ");
        index++;
    }
    return result;
}