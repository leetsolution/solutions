char* toHex(int num) {
    char* hex = (char*)malloc(9 * sizeof(char));
    char hexChars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    int i = 7;
    unsigned int unum = num;
    if (num == 0) {
        hex[0] = '0';
        hex[1] = '\0';
        return hex;
    }
    while (unum > 0 && i >= 0) {
        hex[i] = hexChars[unum % 16];
        unum /= 16;
        i--;
    }
    if (num < 0) {
        while (i >= 0) {
            hex[i] = 'f';
            i--;
        }
    }
    
    int j = 0;
    while(j < 8 && hex[j] == '0'){
        j++;
    }
    
    if(j == 8){
        hex[0] = '0';
        hex[1] = '\0';
    } else {
        memmove(hex, hex + j, 8 - j + 1);
        hex[8 - j] = '\0';
    }
    
    return hex;
}