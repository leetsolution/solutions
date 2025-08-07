bool isLongPressedName(char* name, char* typed) {
    int i = 0, j = 0;
    while (i < strlen(name) && j < strlen(typed)) {
        if (name[i] == typed[j]) {
            int count1 = 0, count2 = 0;
            char c = name[i];
            while (i < strlen(name) && name[i] == c) {
                count1++;
                i++;
            }
            while (j < strlen(typed) && typed[j] == c) {
                count2++;
                j++;
            }
            if (count2 < count1) return false;
        } else {
            return false;
        }
    }
    return i == strlen(name);
}