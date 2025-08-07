class Solution {
    public int maxContainers(int n, int w, int maxWeight) {
        long totalCells = (long) n * n;
        return (int) Math.min(totalCells, maxWeight / w);
    }
}