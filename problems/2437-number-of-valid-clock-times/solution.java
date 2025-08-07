class Solution {
    public int countTime(String time) {
        int ans = 1;
        if (time.charAt(0) == '?' && time.charAt(1) == '?') {
            ans *= 24;
        } else if (time.charAt(0) == '?') {
            if (time.charAt(1) <= '3') {
                ans *= 3;
            } else {
                ans *= 2;
            }
        } else if (time.charAt(1) == '?') {
            if (time.charAt(0) == '0' || time.charAt(0) == '1') {
                ans *= 10;
            } else {
                ans *= 4;
            }
        }

        if (time.charAt(3) == '?' && time.charAt(4) == '?') {
            ans *= 60;
        } else if (time.charAt(3) == '?') {
            ans *= 6;
        } else if (time.charAt(4) == '?') {
            ans *= 10;
        }
        if (time.charAt(0) == '?' && time.charAt(1) == '?' && time.charAt(3) == '?' && time.charAt(4) == '?'){
            return 1440;
        }
        if(time.charAt(0) == '?' && time.charAt(1) == '?'){
            if (time.charAt(3) == '?' && time.charAt(4) == '?'){
                return 1440;
            } else if (time.charAt(3) == '?'){
                 return 24 * 6;
            } else if (time.charAt(4) == '?'){
                return 24 * 10;
            }
        }
         if (time.charAt(3) == '?' && time.charAt(4) == '?'){
             if (time.charAt(0) == '?' && time.charAt(1) == '?'){
                return 1440;
             }else if(time.charAt(0) == '?'){
                 if (time.charAt(1) <= '3') {
                    return 3*60;
                } else {
                    return 2*60;
                }
             } else if(time.charAt(1) == '?'){
                 if (time.charAt(0) == '0' || time.charAt(0) == '1') {
                        return 10*60;
                 }else{
                     return 4 * 60;
                 }
             }
        }
        return ans;
    }
}