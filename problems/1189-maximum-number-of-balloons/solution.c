int maxNumberOfBalloons(char* text) {
    int count[26] = {0};
    for (int i = 0; text[i] != '\0'; i++) {
        count[text[i] - 'a']++;
    }
    int b = count[1];
    int a = count[0];
    int l = count[11] / 2;
    int o = count[14] / 2;
    int n = count[13];
    int min = b;
    if (a < min) min = a;
    if (l < min) min = l;
    if (o < min) min = o;
    if (n < min) min = n;
    return min;
}