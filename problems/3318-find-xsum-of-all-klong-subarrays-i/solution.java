class Solution {
    public int[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        int[] answer = new int[n - k + 1];
        for (int i = 0; i <= n - k; i++) {
            Map<Integer, Integer> freq = new HashMap<>();
            for (int j = i; j < i + k; j++) {
                freq.put(nums[j], freq.getOrDefault(nums[j], 0) + 1);
            }
            List<Map.Entry<Integer, Integer>> list = new ArrayList<>(freq.entrySet());
            Collections.sort(list, (a, b) -> {
                if (a.getValue() != b.getValue()) {
                    return b.getValue() - a.getValue();
                } else {
                    return b.getKey() - a.getKey();
                }
            });
            int sum = 0;
            for (int j = 0; j < Math.min(x, list.size()); j++) {
                int num = list.get(j).getKey();
                int count = list.get(j).getValue();
                for (int l = 0; l < count; l++) {
                    sum += num;
                }
            }
            answer[i] = sum;
        }
        return answer;
    }
}