import java.util.Arrays;

class Solution {
    public int[] answerQueries(int[] nums, int[] queries) {
        Arrays.sort(nums);
        int m = queries.length;
        int[] answer = new int[m];
        for (int i = 0; i < m; i++) {
            int count = 0;
            int sum = 0;
            for (int num : nums) {
                if (sum + num <= queries[i]) {
                    sum += num;
                    count++;
                } else {
                    break;
                }
            }
            answer[i] = count;
        }
        return answer;
    }
}