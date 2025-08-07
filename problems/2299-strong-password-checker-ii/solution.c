bool strongPasswordCheckerII(char* password) {
    int len = 0;
    while (password[len] != '\0') {
        len++;
    }

    if (len < 8) {
        return false;
    }

    bool hasLower = false;
    bool hasUpper = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    char specialChars[] = "!@#$%^&*()-+";
    int specialLen = 12;

    for (int i = 0; i < len; i++) {
        if (islower(password[i])) {
            hasLower = true;
        } else if (isupper(password[i])) {
            hasUpper = true;
        } else if (isdigit(password[i])) {
            hasDigit = true;
        } else {
            for (int j = 0; j < specialLen; j++) {
                if (password[i] == specialChars[j]) {
                    hasSpecial = true;
                    break;
                }
            }
        }

        if (i > 0 && password[i] == password[i - 1]) {
            return false;
        }
    }

    return hasLower && hasUpper && hasDigit && hasSpecial;
}