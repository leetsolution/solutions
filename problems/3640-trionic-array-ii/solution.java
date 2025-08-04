class Solution {
    public int trionic(int[] nums, int s, long[] res) {
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;

        int n = nums.length;

        int i = s + 1;
        for(; i < n && nums[i] > nums[i - 1]; i++, count1++);
        if( count1 == 0) return i;

        int ni = i - 1;
        for(; i < n && nums[i] < nums[i - 1]; i++, count2++);
        if( count2 == 0) return i;

        int ne = i - 1;
        for(; i < n  && nums[i] > nums[i - 1]; i++, count3++);
        if( count3 == 0) return i;

        int e = i - 1;

        long dec = 0;
        for(int idx = ni; idx <= ne; idx++) dec += nums[idx];

        long inc1 = 0;
        long inc2 = 0;

        long inc1_max = -(1L << 52);
        long inc2_max = -(1L << 52);

        for(int idx = ni - 1; idx >= s; idx--) {
            inc1 += nums[idx];
            inc1_max = Math.max(inc1_max, inc1);
        }

        for(int idx = ne + 1; idx <= e; idx++) {
            inc2 += nums[idx];
            inc2_max = Math.max(inc2_max, inc2);
        }

        res[0] = Math.max(res[0], dec + inc1_max + inc2_max);

        return ne;
    }
    
    public long maxSumTrionic(int[] nums) {
        long res[] = new long[]{-(1L << 52)};
        int n = nums.length;
        int i = 0;
        while(i < n) {
            i = trionic(nums, i, res);
        }
        return res[0];
    }
}