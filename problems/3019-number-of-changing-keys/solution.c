int countKeyChanges(char* s) {
    int changes = 0;
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    if (len <= 1) {
        return 0;
    }

    for (int i = 1; i < len; i++) {
        char prev = s[i - 1];
        char curr = s[i];

        if (prev >= 'A' && prev <= 'Z') {
            prev = prev + 32;
        }
        if (curr >= 'A' && curr <= 'Z') {
            curr = curr + 32;
        }

        if (prev != curr) {
            changes++;
        }
    }

    return changes;
}