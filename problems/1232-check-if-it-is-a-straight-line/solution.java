class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        if (coordinates.length <= 2) {
            return true;
        }

        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int x1 = coordinates[1][0], y1 = coordinates[1][1];
        double slope;

        if (x1 - x0 == 0) {
            for (int i = 2; i < coordinates.length; i++) {
                if (coordinates[i][0] - x0 != 0) {
                    return false;
                }
            }
            return true;
        } else {
            slope = (double) (y1 - y0) / (x1 - x0);
            for (int i = 2; i < coordinates.length; i++) {
                double currentSlope;
                if (coordinates[i][0] - x0 == 0) {
                     return false;
                } else {
                    currentSlope = (double) (coordinates[i][1] - y0) / (coordinates[i][0] - x0);
                }
                if (currentSlope != slope) {
                    return false;
                }
            }
            return true;
        }
    }
}