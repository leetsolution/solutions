char* reversePrefix(char* word, char ch) {
    int i = 0;
    while (word[i] != '\0') {
        if (word[i] == ch) {
            int left = 0;
            int right = i;
            while (left < right) {
                char temp = word[left];
                word[left] = word[right];
                word[right] = temp;
                left++;
                right--;
            }
            return word;
        }
        i++;
    }
    return word;
}