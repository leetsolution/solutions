class Solution {
    public boolean canFormArray(int[] arr, int[][] pieces) {
        int n = arr.length;
        int i = 0;
        while (i < n) {
            boolean found = false;
            for (int[] piece : pieces) {
                if (piece[0] == arr[i]) {
                    found = true;
                    for (int j = 0; j < piece.length; j++) {
                        if (i >= n || arr[i] != piece[j]) {
                            return false;
                        }
                        i++;
                    }
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }
}