class Solution {
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Long> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int gift : gifts) {
            pq.offer((long) gift);
        }
        for (int i = 0; i < k; i++) {
            long curr = pq.poll();
            long next = (long) Math.floor(Math.sqrt(curr));
            pq.offer(next);
        }
        long sum = 0;
        while (!pq.isEmpty()) {
            sum += pq.poll();
        }
        return sum;
    }
}