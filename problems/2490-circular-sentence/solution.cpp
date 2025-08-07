class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();
        if (n == 0) return true;

        int wordCount = 0;
        for (char c : sentence) {
            if (c == ' ') {
                wordCount++;
            }
        }
        wordCount++;

        if (wordCount == 1) {
            return sentence[0] == sentence[n - 1];
        }

        int start = 0;
        int end = 0;
        char prevEnd = sentence[0];
        while (end < n) {
            while (end < n && sentence[end] != ' ') {
                end++;
            }

            if (sentence[start] != prevEnd) {
                return false;
            }

            if (end < n) {
                prevEnd = sentence[end - 1];
                start = end + 1;
                end = start;
            } else {
                break;
            }
        }

        return sentence[start] == prevEnd;
    }
};