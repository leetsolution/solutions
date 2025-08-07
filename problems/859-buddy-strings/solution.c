bool buddyStrings(char* s, char* goal) {
    if (strlen(s) != strlen(goal)) return false;
    int n = strlen(s);
    int diff[2] = {-1, -1};
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != goal[i]) {
            if (count == 2) return false;
            diff[count++] = i;
        }
    }
    if (count == 0) {
        int freq[26] = {0};
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
            if (freq[s[i] - 'a'] > 1) return true;
        }
        return false;
    }
    if (count == 2) {
        return s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];
    }
    return false;
}