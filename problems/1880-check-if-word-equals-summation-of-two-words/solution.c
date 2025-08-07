bool isSumEqual(char* firstWord, char* secondWord, char* targetWord) {
    long long num1 = 0, num2 = 0, num3 = 0;
    for (int i = 0; firstWord[i] != '\0'; i++) {
        num1 = num1 * 10 + (firstWord[i] - 'a');
    }
    for (int i = 0; secondWord[i] != '\0'; i++) {
        num2 = num2 * 10 + (secondWord[i] - 'a');
    }
    for (int i = 0; targetWord[i] != '\0'; i++) {
        num3 = num3 * 10 + (targetWord[i] - 'a');
    }
    return num1 + num2 == num3;
}