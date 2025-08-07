class Solution {
    public int reverseDegree(String s) {
        int reverseDegree = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            int alphabetPosition = 26 - (c - 'a');
            reverseDegree += alphabetPosition * (i + 1);
        }
        return reverseDegree;
    }
}