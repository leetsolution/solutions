class Solution {
    public char slowestKey(int[] releaseTimes, String keysPressed) {
        int n = releaseTimes.length;
        char slowest = keysPressed.charAt(0);
        int maxDuration = releaseTimes[0];

        for (int i = 1; i < n; i++) {
            int duration = releaseTimes[i] - releaseTimes[i - 1];
            if (duration > maxDuration) {
                maxDuration = duration;
                slowest = keysPressed.charAt(i);
            } else if (duration == maxDuration) {
                slowest = (char) Math.max(slowest, keysPressed.charAt(i));
            }
        }

        return slowest;
    }
}