import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<Integer> lastVisitedIntegers(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        LinkedList<Integer> seen = new LinkedList<>();
        int k = 0;
        for (int num : nums) {
            if (num > 0) {
                seen.addFirst(num);
                k = 0;
            } else {
                k++;
                if (k <= seen.size()) {
                    ans.add(seen.get(k - 1));
                } else {
                    ans.add(-1);
                }
            }
        }
        return ans;
    }
}