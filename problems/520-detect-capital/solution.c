bool detectCapitalUse(char* word) {
    int n = strlen(word);
    int capital_count = 0;
    for (int i = 0; i < n; i++) {
        if (isupper(word[i])) {
            capital_count++;
        }
    }
    if (capital_count == 0 || capital_count == n || (capital_count == 1 && isupper(word[0]))) {
        return true;
    }
    return false;
}