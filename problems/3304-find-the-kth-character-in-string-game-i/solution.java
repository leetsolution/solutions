class Solution {
    public char kthCharacter(int k) {
        String s = "a";
        int i = 0;
        while (s.length() < k) {
            String next = "";
            for (char c : s.toCharArray()) {
                next += (char) (c + 1);
            }
            s += next;
        }
        return s.charAt(k - 1);
    }
}