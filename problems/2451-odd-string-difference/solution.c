char* oddString(char** words, int wordsSize) {
    int n = strlen(words[0]);
    int diff[wordsSize][n - 1];

    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < n - 1; j++) {
            diff[i][j] = words[i][j + 1] - words[i][j];
        }
    }

    if ((diff[0][0] == diff[1][0] && wordsSize > 2 && diff[0][0] != diff[2][0]) || (wordsSize == 2 && diff[0][0] != diff[1][0]))
    {
         if (diff[0][0] != diff[1][0]){
            if(diff[0][0] == diff[2][0])
                return words[1];
            else
                return words[0];
        }
        else
            return words[2];
    }
    
    for (int i = 1; i < wordsSize; i++) {
        int flag = 0;
        for (int j = 0; j < n - 1; j++) {
            if (diff[0][j] != diff[i][j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            return words[i];
        }
    }
    return words[0];
}