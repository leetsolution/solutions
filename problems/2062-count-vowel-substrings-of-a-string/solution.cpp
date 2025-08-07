class Solution {
public:
    int countVowelSubstrings(string word) {
        int count = 0;
        for (int i = 0; i < word.length(); i++) {
            for (int j = i; j < word.length(); j++) {
                bool a = false, e = false, ii = false, o = false, u = false;
                bool onlyVowels = true;
                for (int k = i; k <= j; k++) {
                    if (word[k] == 'a') a = true;
                    else if (word[k] == 'e') e = true;
                    else if (word[k] == 'i') ii = true;
                    else if (word[k] == 'o') o = true;
                    else if (word[k] == 'u') u = true;
                    else {
                        onlyVowels = false;
                        break;
                    }
                }
                if (onlyVowels && a && e && ii && o && u) {
                    count++;
                }
            }
        }
        return count;
    }
};