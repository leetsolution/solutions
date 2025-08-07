bool hasMatch(char* s, char* p) {
    int s_len = 0;
    while (s[s_len] != '\0') {
        s_len++;
    }
    int p_len = 0;
    while (p[p_len] != '\0') {
        p_len++;
    }

    for (int i = 0; i <= s_len - 1; i++) {
        for (int j = i; j <= s_len; j++) {
            int sub_len = j - i;
            char sub[51] = {0};
            for (int k = 0; k < sub_len; k++) {
                sub[k] = s[i + k];
            }

            int star_index = -1;
            for (int k = 0; k < p_len; k++) {
                if (p[k] == '*') {
                    star_index = k;
                    break;
                }
            }

            if (star_index == -1) {
                if (p_len == sub_len) {
                    int match = 1;
                    for (int k = 0; k < p_len; k++) {
                        if (p[k] != sub[k]) {
                            match = 0;
                            break;
                        }
                    }
                    if (match) return true;
                }
            } else {
                int prefix_len = star_index;
                int suffix_len = p_len - star_index - 1;
                if (prefix_len + suffix_len <= sub_len) {
                    int match = 1;
                    for (int k = 0; k < prefix_len; k++) {
                        if (p[k] != sub[k]) {
                            match = 0;
                            break;
                        }
                    }
                    if (!match) continue;

                    for (int k = 0; k < suffix_len; k++) {
                        if (p[star_index + 1 + k] != sub[sub_len - suffix_len + k]) {
                            match = 0;
                            break;
                        }
                    }
                    if (match) return true;
                }
            }
        }
    }

    return false;
}