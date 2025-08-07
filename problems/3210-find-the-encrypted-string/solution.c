char* getEncryptedString(char* s, int k) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    char* encryptedString = (char*)malloc((len + 1) * sizeof(char));
    if (encryptedString == NULL) {
        return NULL;
    }

    for (int i = 0; i < len; i++) {
        encryptedString[i] = 'a' + (s[i] - 'a' + k) % 26;
    }
    encryptedString[len] = '\0';

    return encryptedString;
}