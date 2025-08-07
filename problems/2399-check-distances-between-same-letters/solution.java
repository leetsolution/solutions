class Solution {
    public boolean checkDistances(String s, int[] distance) {
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            int firstIndex = i;
            int secondIndex = -1;
            for (int j = i + 1; j < s.length(); j++) {
                if (s.charAt(j) == c) {
                    secondIndex = j;
                    break;
                }
            }
            if (secondIndex != -1) {
                int charIndex = c - 'a';
                if (secondIndex - firstIndex - 1 != distance[charIndex]) {
                    return false;
                }
            }
        }
        return true;
    }
}