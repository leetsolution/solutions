class Solution {
    public int minNumber(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<>();
        for (int num : nums1) {
            set1.add(num);
        }
        Set<Integer> set2 = new HashSet<>();
        for (int num : nums2) {
            set2.add(num);
        }
        int min = Integer.MAX_VALUE;
        for (int num1 : nums1) {
            if (set2.contains(num1)) {
                min = Math.min(min, num1);
            }
        }
        if (min != Integer.MAX_VALUE) {
            return min;
        }
        int min1 = Integer.MAX_VALUE;
        for (int num1 : nums1) {
            min1 = Math.min(min1, num1);
        }
        int min2 = Integer.MAX_VALUE;
        for (int num2 : nums2) {
            min2 = Math.min(min2, num2);
        }
        return Integer.parseInt(String.valueOf(Math.min(min1, min2)) + String.valueOf(Math.min(min1 == min2 ? min2 : (set1.contains(min2) ? min1 : min2), (set2.contains(min1) ? min2 : min1))));

    }
}