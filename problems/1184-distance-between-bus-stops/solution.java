class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        int n = distance.length;
        int clockwiseDistance = 0;
        int counterClockwiseDistance = 0;
        int i = start;
        while (i != destination) {
            clockwiseDistance += distance[i];
            i = (i + 1) % n;
        }

        i = start;
        while (i != destination) {
            i = (i - 1 + n) % n;
            counterClockwiseDistance += distance[i];
        }

        return Math.min(clockwiseDistance, counterClockwiseDistance);
    }
}