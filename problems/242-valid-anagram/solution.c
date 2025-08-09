bool isAnagram(char* s, char* t) {
    int s_len = strlen(s);
    int t_len = strlen(t);
    if (s_len != t_len) return false;
    int count[26] = {0};
    for (int i = 0; i < s_len; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }
    return true;
}