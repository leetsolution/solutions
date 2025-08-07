class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        int len = 1;
        while (len < k) {
            string next = "";
            for (char c : word) {
                next += (char)(c + 1);
            }
            word += next;
            len += next.length();
        }
        return word[k - 1];
    }
};