int minimumChairs(char* s) {
    int chairs = 0;
    int maxChairs = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'E') {
            chairs++;
            if (chairs > maxChairs) {
                maxChairs = chairs;
            }
        } else {
            chairs--;
        }
    }
    return maxChairs;
}