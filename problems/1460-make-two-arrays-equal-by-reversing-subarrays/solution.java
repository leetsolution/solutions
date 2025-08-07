class Solution {
    public boolean canBeEqual(int[] target, int[] arr) {
        Map<Integer, Integer> targetMap = new HashMap<>();
        Map<Integer, Integer> arrMap = new HashMap<>();
        for (int num : target) {
            targetMap.put(num, targetMap.getOrDefault(num, 0) + 1);
        }
        for (int num : arr) {
            arrMap.put(num, arrMap.getOrDefault(num, 0) + 1);
        }
        return targetMap.equals(arrMap);
    }
}