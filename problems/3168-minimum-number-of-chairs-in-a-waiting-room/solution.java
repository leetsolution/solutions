class Solution {
    public int minimumChairs(String s) {
        int chairsNeeded = 0;
        int occupiedChairs = 0;
        for (char c : s.toCharArray()) {
            if (c == 'E') {
                occupiedChairs++;
                chairsNeeded = Math.max(chairsNeeded, occupiedChairs);
            } else {
                occupiedChairs--;
            }
        }
        return chairsNeeded;
    }
}