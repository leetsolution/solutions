class Solution {
    public boolean buddyStrings(String s, String goal) {
        if (s.length() != goal.length()) return false;
        if (s.equals(goal)) {
            int[] count = new int[26];
            for (char c : s.toCharArray()) {
                count[c - 'a']++;
                if (count[c - 'a'] > 1) return true;
            }
            return false;
        }
        int diff = 0;
        int i = 0;
        int j = 0;
        for (; i < s.length(); i++) {
            if (s.charAt(i) != goal.charAt(i)) {
                diff++;
                j = i;
            }
            if (diff > 2) return false;
        }
        
        if (diff == 2) {
            return s.charAt(i - 1) == goal.charAt(j) && s.charAt(j) == goal.charAt(i -1);
        }
        return false;

    }
}