import java.util.Arrays;

class Solution {
    public String smallestPalindrome(String s) {
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        return new String(chars);
    }
}