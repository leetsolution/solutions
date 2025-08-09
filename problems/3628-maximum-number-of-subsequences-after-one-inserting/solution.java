class Solution {
    public long numOfSubsequences(String s) {
        long ans = 0;
        long lCount = 0;
        long lcCount = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == 'L') {
                lCount++;
            } else if (c == 'C') {
                lcCount += lCount;
            } else if (c == 'T') {
                ans += lcCount;
            }
        }
        long maxAns = ans;
        lCount = 0;
        lcCount = 0;
        long cCount = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == 'L') {
                long tempAns = ans + lcCount;
                maxAns = Math.max(maxAns, tempAns);
                lCount++;
            } else if (c == 'C') {
                long tempAns = ans + lCount * (getTCount(s, i + 1));
                maxAns = Math.max(maxAns, tempAns);
                lcCount += lCount;
                cCount++;
            } else if (c == 'T') {
                long tempAns = ans + lcCount;
                maxAns = Math.max(maxAns, tempAns);
            }
        }
        lCount = 0;
        lcCount = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == 'L') {
                lCount++;
            } else if (c == 'C') {
                lcCount += lCount;
            } else if (c == 'T') {
                ans += lcCount;
            }
        }
        lCount = 0;
        lcCount = 0;
        cCount = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
        }

        long l_at_end = 0;
        lCount = 0;
        lcCount = 0;
        long tempAns = 0;
        for(int i = 0; i < s.length(); i++){
            char ch = s.charAt(i);
            if(ch == 'L'){
                lCount++;
            } else if (ch == 'C'){
                lcCount += lCount;
            } else if (ch == 'T'){
                tempAns += lcCount;
            }
        }
        l_at_end = tempAns + lcCount;
        maxAns = Math.max(maxAns, l_at_end);

        long c_at_end = 0;
        lCount = 0;
        lcCount = 0;
        tempAns = 0;
        for(int i = 0; i < s.length(); i++){
            char ch = s.charAt(i);
            if(ch == 'L'){
                lCount++;
            } else if (ch == 'C'){
                lcCount += lCount;
            } else if (ch == 'T'){
                tempAns += lcCount;
            }
        }
        c_at_end = tempAns + lCount * getTCount(s, 0);
        maxAns = Math.max(maxAns, c_at_end);
        return maxAns;
    }

    private long getTCount(String s, int start) {
        long count = 0;
        for (int i = start; i < s.length(); i++) {
            if (s.charAt(i) == 'T') {
                count++;
            }
        }
        return count;
    }
}