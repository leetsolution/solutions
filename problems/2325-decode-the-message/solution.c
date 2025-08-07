char* decodeMessage(char* key, char* message) {
    char map[26] = {0};
    char current_char = 'a';
    int key_len = 0;
    while (key[key_len] != '\0') {
        key_len++;
    }

    for (int i = 0; i < key_len; i++) {
        if (key[i] != ' ' && map[key[i] - 'a'] == 0) {
            map[key[i] - 'a'] = current_char;
            current_char++;
        }
    }

    int message_len = 0;
    while (message[message_len] != '\0') {
        message_len++;
    }
    
    char* decoded_message = (char*)malloc((message_len + 1) * sizeof(char));

    for (int i = 0; i < message_len; i++) {
        if (message[i] == ' ') {
            decoded_message[i] = ' ';
        } else {
            decoded_message[i] = map[message[i] - 'a'];
        }
    }

    decoded_message[message_len] = '\0';

    return decoded_message;
}