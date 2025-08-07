import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    public int[] findEvenNumbers(int[] digits) {
        Set<Integer> result = new HashSet<>();
        for (int i = 0; i < digits.length; i++) {
            for (int j = 0; j < digits.length; j++) {
                for (int k = 0; k < digits.length; k++) {
                    if (i != j && i != k && j != k) {
                        int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                        if (num >= 100 && num % 2 == 0) {
                            result.add(num);
                        }
                    }
                }
            }
        }
        List<Integer> list = new ArrayList<>(result);
        Collections.sort(list);
        int[] arr = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            arr[i] = list.get(i);
        }
        return arr;
    }
}