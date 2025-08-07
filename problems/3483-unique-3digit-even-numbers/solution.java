import java.util.HashSet;
import java.util.Set;

class Solution {
    public int totalNumbers(int[] digits) {
        Set<Integer> distinctNumbers = new HashSet<>();
        for (int i = 0; i < digits.length; i++) {
            for (int j = 0; j < digits.length; j++) {
                for (int k = 0; k < digits.length; k++) {
                    if (i != j && i != k && j != k && digits[i] != 0 && digits[k] % 2 == 0) {
                        int number = digits[i] * 100 + digits[j] * 10 + digits[k];
                        distinctNumbers.add(number);
                    }
                }
            }
        }
        return distinctNumbers.size();
    }
}