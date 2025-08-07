class Solution {
    public int captureForts(int[] forts) {
        int maxCaptured = 0;
        for (int i = 0; i < forts.length; i++) {
            if (forts[i] == 1) {
                for (int j = 0; j < forts.length; j++) {
                    if (forts[j] == -1) {
                        int captured = 0;
                        boolean valid = true;
                        int start = Math.min(i, j) + 1;
                        int end = Math.max(i, j);
                        for (int k = start; k < end; k++) {
                            if (forts[k] != 0) {
                                valid = false;
                                break;
                            } else {
                                captured++;
                            }
                        }
                        if (valid) {
                            maxCaptured = Math.max(maxCaptured, captured);
                        }
                    }
                }
            }
        }
        return maxCaptured;
    }
}