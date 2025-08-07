int generateKey(int num1, int num2, int num3) {
    char s1[5], s2[5], s3[5];
    sprintf(s1, "%04d", num1);
    sprintf(s2, "%04d", num2);
    sprintf(s3, "%04d", num3);
    char key[5] = "";
    for (int i = 0; i < 4; i++) {
        key[i] = min(min(s1[i], s2[i]), s3[i]);
    }
    key[4] = '\0';
    return atoi(key);
}