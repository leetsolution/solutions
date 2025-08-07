class Solution {
    public String findValidPair(String s) {
        int n = s.length();
        for (int i = 0; i < n - 1; i++) {
            char first = s.charAt(i);
            char second = s.charAt(i + 1);

            if (first != second) {
                int firstDigit = first - '0';
                int secondDigit = second - '0';

                int firstCount = 0;
                int secondCount = 0;

                for (int j = 0; j < n; j++) {
                    if (s.charAt(j) == first) {
                        firstCount++;
                    }
                    if (s.charAt(j) == second) {
                        secondCount++;
                    }
                }

                if (firstCount == firstDigit && secondCount == secondDigit) {
                    return "" + first + second;
                }
            }
        }
        return "";
    }
}