class Solution {
    public int rearrangeCharacters(String s, String target) {
        int[] sCount = new int[26];
        int[] targetCount = new int[26];

        for (char c : s.toCharArray()) {
            sCount[c - 'a']++;
        }

        for (char c : target.toCharArray()) {
            targetCount[c - 'a']++;
        }

        int result = Integer.MAX_VALUE;
        for (int i = 0; i < 26; i++) {
            if (targetCount[i] > 0) {
                if (sCount[i] == 0) return 0;
                result = Math.min(result, sCount[i] / targetCount[i]);
            }
        }

        return result;
    }
}