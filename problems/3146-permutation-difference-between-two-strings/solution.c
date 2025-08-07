int findPermutationDifference(char* s, char* t) {
    int diff = 0;
    int s_len = 0;
    while (s[s_len] != '\0') {
        s_len++;
    }

    for (int i = 0; i < s_len; i++) {
        int s_index = i;
        int t_index = -1;
        for (int j = 0; j < s_len; j++) {
            if (s[i] == t[j]) {
                t_index = j;
                break;
            }
        }
        diff += abs(s_index - t_index);
    }

    return diff;
}