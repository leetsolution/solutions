class Solution {
    public int maxHeightOfTriangle(int red, int blue) {
        int left = 0;
        int right = (int) Math.sqrt(2 * (red + blue));
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int totalBalls = mid * (mid + 1) / 2;

            if (totalBalls <= red + blue) {
                int redUsed = 0;
                int blueUsed = 0;
                boolean possible = false;

                for (int i = 0; i < (1 << mid); i++) {
                    int tempRed = 0;
                    int tempBlue = 0;
                    boolean valid = true;

                    for (int j = 0; j < mid; j++) {
                        int ballsInRow = j + 1;
                        if ((i >> j) % 2 == 0) {
                            tempRed += ballsInRow;
                        } else {
                            tempBlue += ballsInRow;
                        }
                    }

                    if (tempRed <= red && tempBlue <= blue) {
                        
                        boolean alternate = true;
                        for(int k = 0; k < mid - 1; k++){
                            if(((i >> k) % 2) == ((i >> (k+1)) % 2)){
                                alternate = false;
                                break;
                            }
                        }

                        if(alternate){
                            possible = true;
                            break;
                        }
                    }
                }

                if (possible) {
                    ans = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
}