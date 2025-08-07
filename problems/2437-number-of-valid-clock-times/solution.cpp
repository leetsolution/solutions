class Solution {
public:
    int countTime(string time) {
        int ans = 1;
        if (time[0] == '?' && time[1] == '?') {
            ans *= 24;
        } else if (time[0] == '?') {
            if (time[1] >= '0' && time[1] <= '3') {
                ans *= 3;
            } else {
                ans *= 2;
            }
        } else if (time[1] == '?') {
            if (time[0] == '0' || time[0] == '1') {
                ans *= 10;
            } else {
                ans *= 4;
            }
        }

        if (time[3] == '?' && time[4] == '?') {
            ans *= 60;
        } else if (time[3] == '?') {
            ans *= 6;
        } else if (time[4] == '?') {
            ans *= 10;
        }
        
        if(time[0] != '?' && time[1] != '?'){
            int hours = (time[0] - '0') * 10 + (time[1] - '0');
            if(hours > 23) return 0;
        }
         if(time[3] != '?' && time[4] != '?'){
            int minutes = (time[3] - '0') * 10 + (time[4] - '0');
            if(minutes > 59) return 0;
        }

        if(time[0] != '?' && time[1] != '?'){
             int hours = (time[0] - '0') * 10 + (time[1] - '0');
             if (hours > 23) return 0;
        }

        if(time[3] != '?' && time[4] != '?'){
            int minutes = (time[3] - '0') * 10 + (time[4] - '0');
            if(minutes > 59) return 0;
        }
        if(time[0] == '?' && time[1] == '?'){
             ans = 24;
        } else if (time[0] == '?'){
            if(time[1] >= '0' && time[1] <= '3'){
                ans = 3;
            } else {
                ans = 2;
            }
        } else if (time[1] == '?'){
            if(time[0] == '0' || time[0] == '1'){
                ans = 10;
            } else {
                ans = 4;
            }
        } else {
            ans = 1;
        }

        if (time[3] == '?' && time[4] == '?') {
             ans *= 60;
        } else if (time[3] == '?') {
             ans *= 6;
        } else if (time[4] == '?') {
            ans *= 10;
        } else {
            ans *= 1;
        }


        return ans;
    }
};