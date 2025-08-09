class Solution {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int num : nums) {
            countMap.put(num, countMap.getOrDefault(num, 0) + 1);
        }
        int maxLength = 0;
        for (int num : countMap.keySet()) {
            if (countMap.containsKey(num + 1)) {
                maxLength = Math.max(maxLength, countMap.get(num) + countMap.get(num + 1));
            }
        }
        return maxLength;
    }
}