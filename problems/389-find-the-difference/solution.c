char findTheDifference(char* s, char* t) {
    int s_sum = 0;
    int t_sum = 0;
    int i = 0;
    while (s[i] != '\0') {
        s_sum += s[i];
        i++;
    }
    i = 0;
    while (t[i] != '\0') {
        t_sum += t[i];
        i++;
    }
    return (char)(t_sum - s_sum);
}