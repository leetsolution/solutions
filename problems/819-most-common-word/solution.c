#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 20
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;


int compareWords(const void *a, const void *b) {
    WordCount *wa = (WordCount *)a;
    WordCount *wb = (WordCount *)b;
    return wb->count - wa->count;
}

char* mostCommonWord(char* paragraph, char** banned, int bannedSize) {
    char *word = strtok(paragraph, "!?',;. ");
    WordCount wordCounts[MAX_WORDS];
    int wordCountIndex = 0;
    int bannedCount[MAX_WORDS];
    
    for (int i =0; i < MAX_WORDS; i++){
        bannedCount[i] = 0;
    }

    
    for (int i = 0; i < bannedSize; i++) {
        bannedCount[i] = 1;
    }

    while (word != NULL) {
        int len = strlen(word);
        for (int i = 0; i < len; i++) {
            word[i] = tolower(word[i]);
        }
        int found = 0;
        for (int i = 0; i < wordCountIndex; i++) {
            if (strcmp(word, wordCounts[i].word) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(wordCounts[wordCountIndex].word, word);
            wordCounts[wordCountIndex].count = 1;
            wordCountIndex++;
        }
        word = strtok(NULL, "!?',;. ");
    }

    qsort(wordCounts, wordCountIndex, sizeof(WordCount), compareWords);

    for (int i = 0; i < wordCountIndex; i++) {
        int isBanned = 0;
        for (int j = 0; j < bannedSize; j++) {
            if (strcmp(wordCounts[i].word, banned[j]) == 0) {
                isBanned = 1;
                break;
            }
        }
        if (!isBanned) {
            return wordCounts[i].word;
        }
    }
    return NULL;
}