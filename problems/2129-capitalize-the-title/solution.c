char* capitalizeTitle(char* title) {
    int len = strlen(title);
    int wordStart = 0;
    for (int i = 0; i <= len; i++) {
        if (i == len || title[i] == ' ') {
            int wordLen = i - wordStart;
            if (wordLen <= 2) {
                for (int j = wordStart; j < i; j++) {
                    if (title[j] >= 'A' && title[j] <= 'Z') {
                        title[j] = title[j] - 'A' + 'a';
                    }
                }
            } else {
                if (title[wordStart] >= 'a' && title[wordStart] <= 'z') {
                    title[wordStart] = title[wordStart] - 'a' + 'A';
                }
                for (int j = wordStart + 1; j < i; j++) {
                    if (title[j] >= 'A' && title[j] <= 'Z') {
                        title[j] = title[j] - 'A' + 'a';
                    } else if (title[j] >= 'a' && title[j] <= 'z') {

                    }
                }
            }
            wordStart = i + 1;
        }
    }
    return title;
}