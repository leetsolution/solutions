class Solution {
    public int findPermutationDifference(String s, String t) {
        int permutationDifference = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            int indexInS = i;
            int indexInT = t.indexOf(c);
            permutationDifference += Math.abs(indexInS - indexInT);
        }
        return permutationDifference;
    }
}