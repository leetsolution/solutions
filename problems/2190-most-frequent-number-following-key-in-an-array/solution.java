class Solution {
    public int mostFrequent(int[] nums, int key) {
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] == key) {
                int target = nums[i + 1];
                countMap.put(target, countMap.getOrDefault(target, 0) + 1);
            }
        }
        int maxCount = 0;
        int result = -1;
        for (Map.Entry<Integer, Integer> entry : countMap.entrySet()) {
            if (entry.getValue() > maxCount) {
                maxCount = entry.getValue();
                result = entry.getKey();
            }
        }
        return result;
    }
}