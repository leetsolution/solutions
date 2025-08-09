bool canConstruct(char* ransomNote, char* magazine) {
    int ransomNoteLength = strlen(ransomNote);
    int magazineLength = strlen(magazine);
    int ransomNoteFreq[26] = {0};
    int magazineFreq[26] = {0};

    for (int i = 0; i < ransomNoteLength; i++) {
        ransomNoteFreq[ransomNote[i] - 'a']++;
    }

    for (int i = 0; i < magazineLength; i++) {
        magazineFreq[magazine[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (ransomNoteFreq[i] > magazineFreq[i]) {
            return false;
        }
    }

    return true;
}