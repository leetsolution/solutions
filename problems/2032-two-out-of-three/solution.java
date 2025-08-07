import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    public List<Integer> twoOutOfThree(int[] nums1, int[] nums2, int[] nums3) {
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();
        Set<Integer> set3 = new HashSet<>();

        for (int num : nums1) {
            set1.add(num);
        }
        for (int num : nums2) {
            set2.add(num);
        }
        for (int num : nums3) {
            set3.add(num);
        }

        Set<Integer> result = new HashSet<>();

        for (int num : set1) {
            if (set2.contains(num) || set3.contains(num)) {
                result.add(num);
            }
        }

        for (int num : set2) {
            if (set1.contains(num) || set3.contains(num)) {
                result.add(num);
            }
        }

        List<Integer> list = new ArrayList<>(result);
        return list;
    }
}