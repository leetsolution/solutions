class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] magCount = new int[26];
        int[] ranCount = new int[26];

        for (char c : magazine.toCharArray()) {
            magCount[c - 'a']++;
        }

        for (char c : ransomNote.toCharArray()) {
            ranCount[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (ranCount[i] > magCount[i]) {
                return false;
            }
        }

        return true;
    }
}