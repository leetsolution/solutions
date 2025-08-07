class Solution {
    public String oddString(String[] words) {
        int n = words.length;
        int len = words[0].length();

        int[] diff0 = new int[len - 1];
        for (int i = 0; i < len - 1; i++) {
            diff0[i] = words[0].charAt(i + 1) - words[0].charAt(i);
        }

        int[] diff1 = new int[len - 1];
        for (int i = 0; i < len - 1; i++) {
            diff1[i] = words[1].charAt(i + 1) - words[1].charAt(i);
        }

        int[] diff2 = new int[len - 1];
        for (int i = 0; i < len - 1; i++) {
            diff2[i] = words[2].charAt(i + 1) - words[2].charAt(i);
        }

        boolean firstEqualsSecond = true;
        for (int i = 0; i < len - 1; i++) {
            if (diff0[i] != diff1[i]) {
                firstEqualsSecond = false;
                break;
            }
        }

        boolean firstEqualsThird = true;
        for (int i = 0; i < len - 1; i++) {
            if (diff0[i] != diff2[i]) {
                firstEqualsThird = false;
                break;
            }
        }

        if (firstEqualsSecond && !firstEqualsThird) {
            return words[2];
        }

        if (!firstEqualsSecond && firstEqualsThird) {
            return words[1];
        }

        for (int i = 3; i < n; i++) {
            int[] diff = new int[len - 1];
            for (int j = 0; j < len - 1; j++) {
                diff[j] = words[i].charAt(j + 1) - words[i].charAt(j);
            }

            boolean equalsFirst = true;
            for (int j = 0; j < len - 1; j++) {
                if (diff0[j] != diff[j]) {
                    equalsFirst = false;
                    break;
                }
            }

            if (!equalsFirst) {
                return words[i];
            }
        }

        return words[0];
    }
}