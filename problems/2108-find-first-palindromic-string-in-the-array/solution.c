#include <string.h>
#include <stdbool.h>

char* firstPalindrome(char** words, int wordsSize) {
    for (int i = 0; i < wordsSize; i++) {
        int left = 0;
        int right = strlen(words[i]) - 1;
        bool isPalindrome = true;
        while (left < right) {
            if (words[i][left] != words[i][right]) {
                isPalindrome = false;
                break;
            }
            left++;
            right--;
        }
        if (isPalindrome) {
            return words[i];
        }
    }
    return "";
}