import java.util.*;
class Solution {
    public int[] minBitwiseArray(List<Integer> nums) {
        int n = nums.size();
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            int num = nums.get(i);
            int x = -1;
            for (int j = 0; j < num; j++) {
                if ((j | (j + 1)) == num) {
                    x = j;
                    break;
                }
            }
            ans[i] = x;
        }
        return ans;
    }
}