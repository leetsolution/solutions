class Solution {
    public int possibleStringCount(String word) {
        int count = 1;
        int n = word.length();
        for (int i = 0; i < n - 1; i++) {
            if (word.charAt(i) == word.charAt(i + 1)) {
                int j = i + 1;
                while (j < n && word.charAt(i) == word.charAt(j)) {
                    j++;
                }
                count += (j - i - 1);
                i = j - 1;
            }
        }
        return count;
    }
}