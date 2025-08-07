bool canBeEqual(char* s1, char* s2) {
    char s1_even[3] = {s1[0], s1[2], '\0'};
    char s1_odd[3] = {s1[1], s1[3], '\0'};
    char s2_even[3] = {s2[0], s2[2], '\0'};
    char s2_odd[3] = {s2[1], s2[3], '\0'};
    
    char temp;
    if (s1_even[0] > s1_even[1]) {
        temp = s1_even[0];
        s1_even[0] = s1_even[1];
        s1_even[1] = temp;
    }
    if (s1_odd[0] > s1_odd[1]) {
        temp = s1_odd[0];
        s1_odd[0] = s1_odd[1];
        s1_odd[1] = temp;
    }
    if (s2_even[0] > s2_even[1]) {
        temp = s2_even[0];
        s2_even[0] = s2_even[1];
        s2_even[1] = temp;
    }
    if (s2_odd[0] > s2_odd[1]) {
        temp = s2_odd[0];
        s2_odd[0] = s2_odd[1];
        s2_odd[1] = temp;
    }
    
    if (s1_even[0] == s2_even[0] && s1_even[1] == s2_even[1] &&
        s1_odd[0] == s2_odd[0] && s1_odd[1] == s2_odd[1]) {
        return true;
    } else {
        return false;
    }
}