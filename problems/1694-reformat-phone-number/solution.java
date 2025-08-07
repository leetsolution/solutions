class Solution {
    public String reformatNumber(String number) {
        StringBuilder digits = new StringBuilder();
        for (char c : number.toCharArray()) {
            if (Character.isDigit(c)) {
                digits.append(c);
            }
        }

        int n = digits.length();
        StringBuilder result = new StringBuilder();
        int i = 0;

        while (n - i > 4) {
            result.append(digits.substring(i, i + 3)).append("-");
            i += 3;
        }

        if (n - i == 4) {
            result.append(digits.substring(i, i + 2)).append("-").append(digits.substring(i + 2, i + 4));
        } else if (n - i == 3) {
            result.append(digits.substring(i, i + 3));
        } else if (n - i == 2) {
            result.append(digits.substring(i, i + 2));
        }

        return result.toString();
    }
}