int maxFreqSum(char* s) {
    int vowelFreq[5] = {0};
    int consonantFreq[26] = {0};
    int maxVowelFreq = 0;
    int maxConsonantFreq = 0;
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    for (int i = 0; i < len; i++) {
        if (s[i] == 'a') {
            vowelFreq[0]++;
        } else if (s[i] == 'e') {
            vowelFreq[1]++;
        } else if (s[i] == 'i') {
            vowelFreq[2]++;
        } else if (s[i] == 'o') {
            vowelFreq[3]++;
        } else if (s[i] == 'u') {
            vowelFreq[4]++;
        } else {
            consonantFreq[s[i] - 'a']++;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (vowelFreq[i] > maxVowelFreq) {
            maxVowelFreq = vowelFreq[i];
        }
    }

    for (int i = 0; i < 26; i++) {
        if (s[0] + i != 'a' && s[0] + i != 'e' && s[0] + i != 'i' && s[0] + i != 'o' && s[0] + i != 'u' && consonantFreq[i] > maxConsonantFreq) {
            maxConsonantFreq = consonantFreq[i];
        }

        if(s[0] + i == 'a' || s[0] + i == 'e' || s[0] + i == 'i' || s[0] + i == 'o' || s[0] + i == 'u'){
            consonantFreq[i] = 0;
        }
        if(consonantFreq[i] > maxConsonantFreq){
            maxConsonantFreq = consonantFreq[i];
        }

    }

    return maxVowelFreq + maxConsonantFreq;
}