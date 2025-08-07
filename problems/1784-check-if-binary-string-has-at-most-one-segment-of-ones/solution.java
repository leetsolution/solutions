class Solution {
    public boolean checkOnesSegment(String s) {
        int n = s.length();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '1') {
                count++;
                while (i < n && s.charAt(i) == '1') {
                    i++;
                }
                if (i < n && s.charAt(i) == '0') {
                    while (i < n && s.charAt(i) == '0') {
                        i++;
                    }
                    if (i < n && s.charAt(i) == '1') {
                        return false;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
        }
        return true;
    }
}