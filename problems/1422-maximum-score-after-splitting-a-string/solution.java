class Solution {
    public int maxScore(String s) {
        int max_score = 0;
        for (int i = 1; i < s.length(); i++) {
            String left = s.substring(0, i);
            String right = s.substring(i);
            int left_zeros = 0;
            for (char c : left.toCharArray()) {
                if (c == '0') {
                    left_zeros++;
                }
            }
            int right_ones = 0;
            for (char c : right.toCharArray()) {
                if (c == '1') {
                    right_ones++;
                }
            }
            int score = left_zeros + right_ones;
            max_score = Math.max(max_score, score);
        }
        return max_score;
    }
}