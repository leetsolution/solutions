class Solution {
    public int maxDifference(String s) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        int maxOdd = Integer.MIN_VALUE;
        int minEven = Integer.MAX_VALUE;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 0 && freq[i] > 0) {
                minEven = Math.min(minEven, freq[i]);
            } else if (freq[i] % 2 != 0) {
                maxOdd = Math.max(maxOdd, freq[i]);
            }
        }
        
        if (maxOdd == Integer.MIN_VALUE || minEven == Integer.MAX_VALUE){
            int odd = Integer.MIN_VALUE;
            int even = Integer.MAX_VALUE;
            for(int i=0; i<26; ++i){
                if(freq[i] % 2 != 0){
                    if(odd == Integer.MIN_VALUE){
                        odd = freq[i];
                    } else{
                       odd = Math.max(odd, freq[i]); 
                    }
                }
                if(freq[i] % 2 == 0 && freq[i] > 0){
                    if(even == Integer.MAX_VALUE){
                       even = freq[i]; 
                    } else {
                        even = Math.min(even, freq[i]);
                    }
                    
                }
            }
             if(odd == Integer.MIN_VALUE || even == Integer.MAX_VALUE){
                return 0;
            }

            return odd - even;

        }

        return maxOdd - minEven;
    }
}