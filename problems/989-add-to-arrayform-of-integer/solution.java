import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public List<Integer> addToArrayForm(int[] num, int k) {
        List<Integer> result = new ArrayList<>();
        int n = num.length;
        int carry = 0;
        for (int i = n - 1; i >= 0; i--) {
            int sum = num[i] + k % 10 + carry;
            k /= 10;
            carry = sum / 10;
            result.add(sum % 10);
        }
        while (k > 0) {
            int sum = k % 10 + carry;
            k /= 10;
            carry = sum / 10;
            result.add(sum % 10);
        }
        if (carry > 0) {
            result.add(carry);
        }
        Collections.reverse(result);
        return result;
    }
}