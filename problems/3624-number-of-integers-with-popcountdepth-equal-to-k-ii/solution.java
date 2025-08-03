class Solution {
    public int[] popcountDepth(long[] nums, long[][] queries) {
    class Solution {
        public List<Integer> solve(long[] nums, int[][] queries) {
            List<Integer> ans = new ArrayList<>();
            for (int[] query : queries) {
                if (query[0] == 1) {
                    int l = query[1];
                    int r = query[2];
                    int k = query[3];
                    int count = 0;
                    for (int i = l; i <= r; i++) {
                        if (getPopcountDepth(nums[i]) == k) {
                            count++;
                        }
                    }
                    ans.add(count);
                } else {
                    nums[query[1]] = query[2];
                }
            }
            return ans;
        }

        private int getPopcountDepth(long n) {
            int depth = 0;
            while (n != 1) {
                n = Long.bitCount(n);
                depth++;
            }
            return depth;
        }
    }
}