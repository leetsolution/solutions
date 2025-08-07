class Solution {
    public int countValidSelections(int[] nums) {
        int count = 0;
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (isValid(nums.clone(), i, 1)) {
                    count++;
                }
                if (isValid(nums.clone(), i, -1)) {
                    count++;
                }
            }
        }

        return count;
    }

    private boolean isValid(int[] nums, int curr, int direction) {
        int n = nums.length;

        while (curr >= 0 && curr < n) {
            if (nums[curr] == 0) {
                curr += direction;
            } else {
                nums[curr]--;
                direction *= -1;
                curr += direction;
            }
        }

        for (int num : nums) {
            if (num != 0) {
                return false;
            }
        }

        return true;
    }
}