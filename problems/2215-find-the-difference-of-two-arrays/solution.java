import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;

class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();

        for (int num : nums1) {
            set1.add(num);
        }
        for (int num : nums2) {
            set2.add(num);
        }

        List<Integer> list1 = new ArrayList<>();
        for (int num : nums1) {
            if (!set2.contains(num)) {
                if (!list1.contains(num)) {
                    list1.add(num);
                }
            }
        }

        List<Integer> list2 = new ArrayList<>();
        for (int num : nums2) {
            if (!set1.contains(num)) {
                if (!list2.contains(num)) {
                    list2.add(num);
                }
            }
        }

        List<List<Integer>> result = new ArrayList<>();
        result.add(list1);
        result.add(list2);

        return result;
    }
}