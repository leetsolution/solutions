class Solution {
    public int findMinimumOperations(String s1, String s2, String s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        int i = n1 - 1;
        int j = n2 - 1;
        int k = n3 - 1;
        int operations = 0;
        while (i >= 0 && j >= 0 && k >= 0) {
            if (s1.charAt(i) == s2.charAt(j) && s2.charAt(j) == s3.charAt(k)) {
                i--;
                j--;
                k--;
            } else {
                operations++;
                if (i > j && i > k) {
                    i--;
                } else if (j > i && j > k) {
                    j--;
                } else if (k > i && k > j) {
                    k--;
                } else {
                    return -1;
                }
            }
        }
        if (i >= 0 || j >= 0 || k >= 0) {
            return -1;
        }
        return operations;
    }
}