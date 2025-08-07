class Solution {
    public String[] divideString(String s, int k, char fill) {
        int n = s.length();
        int numGroups = (int) Math.ceil((double) n / k);
        String[] result = new String[numGroups];
        int index = 0;

        for (int i = 0; i < numGroups; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < k; j++) {
                int currentIndex = i * k + j;
                if (currentIndex < n) {
                    sb.append(s.charAt(currentIndex));
                } else {
                    sb.append(fill);
                }
            }
            result[i] = sb.toString();
        }

        return result;
    }
}