class Solution {
    public int[] fairCandySwap(int[] aliceSizes, int[] bobSizes) {
        int sumAlice = 0;
        int sumBob = 0;
        for (int size : aliceSizes) {
            sumAlice += size;
        }
        for (int size : bobSizes) {
            sumBob += size;
        }
        Set<Integer> setBob = new HashSet<>();
        for (int size : bobSizes) {
            setBob.add(size);
        }
        for (int size : aliceSizes) {
            int target = (sumAlice - size + sumBob - size) / 2;
            if (setBob.contains(target)) {
                return new int[]{size, target};
            }
        }
        return new int[]{};
    }
}