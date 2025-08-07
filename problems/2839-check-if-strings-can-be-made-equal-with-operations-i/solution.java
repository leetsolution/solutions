class Solution {
    public boolean canBeEqual(String s1, String s2) {
        String s1_even = "";
        String s1_odd = "";
        String s2_even = "";
        String s2_odd = "";

        for (int i = 0; i < 4; i++) {
            if (i % 2 == 0) {
                s1_even += s1.charAt(i);
                s2_even += s2.charAt(i);
            } else {
                s1_odd += s1.charAt(i);
                s2_odd += s2.charAt(i);
            }
        }

        char[] even1 = s1_even.toCharArray();
        char[] even2 = s2_even.toCharArray();
        char[] odd1 = s1_odd.toCharArray();
        char[] odd2 = s2_odd.toCharArray();

        java.util.Arrays.sort(even1);
        java.util.Arrays.sort(even2);
        java.util.Arrays.sort(odd1);
        java.util.Arrays.sort(odd2);

        return java.util.Arrays.equals(even1, even2) && java.util.Arrays.equals(odd1, odd2);
    }
}