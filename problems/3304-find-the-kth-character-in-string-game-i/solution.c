char kthCharacter(int k) {
    char word = 'a';
    int len = 1;
    while (len < k) {
        char next = word + 1;
        if (next > 'z') next = 'a';
        int nextLen = len;
        while (nextLen < k && nextLen < 2 * len) {
            word = next;
            nextLen++;
        }
        len *= 2;
    }
    
    return word;
}