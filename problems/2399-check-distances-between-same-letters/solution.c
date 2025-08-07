bool checkDistances(char* s, int* distance, int distanceSize) {
    int first[26];
    for (int i = 0; i < 26; i++) {
        first[i] = -1;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';
        if (first[index] == -1) {
            first[index] = i;
        } else {
            int dist = i - first[index] - 1;
            if (dist != distance[index]) {
                return false;
            }
        }
    }

    return true;
}