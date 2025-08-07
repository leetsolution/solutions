import java.util.ArrayList;
import java.util.List;

class Solution {
    public int minimumPairRemoval(int[] nums) {
        int count = 0;
        List<Integer> list = new ArrayList<>();
        for (int num : nums) {
            list.add(num);
        }

        while (true) {
            boolean sorted = true;
            for (int i = 0; i < list.size() - 1; i++) {
                if (list.get(i) > list.get(i + 1)) {
                    sorted = false;
                    break;
                }
            }
            if (sorted) {
                break;
            }

            int minSum = Integer.MAX_VALUE;
            int minIndex = -1;

            for (int i = 0; i < list.size() - 1; i++) {
                int sum = list.get(i) + list.get(i + 1);
                if (sum < minSum) {
                    minSum = sum;
                    minIndex = i;
                }
            }

            if (minIndex != -1) {
                int sum = list.get(minIndex) + list.get(minIndex + 1);
                list.set(minIndex, sum);
                list.remove(minIndex + 1);
                count++;
            } else {
                break;
            }
        }

        return count;
    }
}