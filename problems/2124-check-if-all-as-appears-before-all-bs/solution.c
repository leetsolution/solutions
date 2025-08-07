bool checkString(char* s) {
    int b_found = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'b') {
            b_found = 1;
        } else if (s[i] == 'a' && b_found) {
            return false;
        }
    }
    return true;
}