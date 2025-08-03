class Solution {
    public long maxSumTrionic(int[] nums) {
        int n = nums.length;
        if (n < 4) {
            return Long.MIN_VALUE;
        }

        long[] prefix = new long[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // Part 1: Pre-computation for the first increasing segment [l...p]
        // For each potential endpoint p, find the minimum prefix sum of a valid start l.
        int[] incRunStart = new int[n];
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                incRunStart[i] = incRunStart[i - 1];
            } else {
                incRunStart[i] = i;
            }
        }

        long[] minPrefixForP = new long[n];
        java.util.ArrayDeque<Integer> minDeque = new java.util.ArrayDeque<>();
        for (int p = 1; p < n; p++) {
            int l_start = incRunStart[p];
            int l_end = p - 1;
            if (l_start > l_end) {
                minPrefixForP[p] = Long.MAX_VALUE;
                continue;
            }
            // Maintain deque for current window [l_start, l_end]
            if (!minDeque.isEmpty() && minDeque.peekFirst() < l_start) {
                 minDeque.pollFirst();
            }
            while (!minDeque.isEmpty() && prefix[minDeque.peekLast()] >= prefix[l_end]) {
                minDeque.pollLast();
            }
            minDeque.offerLast(l_end);
            minPrefixForP[p] = prefix[minDeque.peekFirst()];
        }


        // Part 3: Pre-computation for the third increasing segment [q...r]
        // For each potential startpoint q, find the maximum prefix sum of a valid end r.
        int[] incRunEnd = new int[n];
        incRunEnd[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            incRunEnd[i] = (nums[i] < nums[i + 1]) ? incRunEnd[i + 1] : i;
        }

        long[] maxPrefixForQ = new long[n];
        java.util.ArrayDeque<Integer> maxDeque = new java.util.ArrayDeque<>();
        for (int q = n - 2; q >= 0; q--) {
            int r_start = q + 1;
            int r_end = incRunEnd[r_start];
             if (r_start > r_end) {
                maxPrefixForQ[q] = Long.MIN_VALUE;
                continue;
            }
            if (!maxDeque.isEmpty() && maxDeque.peekFirst() > r_end) {
                maxDeque.pollFirst();
            }
            while(!maxDeque.isEmpty() && prefix[maxDeque.peekLast() + 1] <= prefix[r_start + 1]) {
                maxDeque.pollLast();
            }
            maxDeque.offerLast(r_start);
            maxPrefixForQ[q] = prefix[maxDeque.peekFirst() + 1];
        }

        // Part 2: Pre-computation for the decreasing segment [p...q]
        int[] decRunStart = new int[n];
        for (int i = 1; i < n; i++) {
            decRunStart[i] = (nums[i] < nums[i - 1]) ? decRunStart[i - 1] : i;
        }

        // Main loop to combine the segments
        long maxSum = Long.MIN_VALUE;
        for (int p = 1; p <= n - 3; p++) {
            if (minPrefixForP[p] == Long.MAX_VALUE) {
                continue;
            }
            for (int q = p + 1; q <= n - 2; q++) {
                if (decRunStart[q] <= p) {
                    if (maxPrefixForQ[q] != Long.MIN_VALUE) {
                        maxSum = Math.max(maxSum, maxPrefixForQ[q] - minPrefixForP[p]);
                    }
                }
            }
        }

        return maxSum == Long.MIN_VALUE ? 0 : maxSum;
    }
}