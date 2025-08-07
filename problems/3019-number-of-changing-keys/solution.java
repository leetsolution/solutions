class Solution {
    public int countKeyChanges(String s) {
        int count = 0;
        if (s.length() == 0) {
            return 0;
        }
        char prev = Character.toLowerCase(s.charAt(0));
        for (int i = 1; i < s.length(); i++) {
            char curr = Character.toLowerCase(s.charAt(i));
            if (curr != prev) {
                count++;
                prev = curr;
            }
        }
        return count;
    }
}