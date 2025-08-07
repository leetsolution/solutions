int countTime(char* time) {
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

    if (time[0] != '?' && time[1] != '?') {
        int hh = (time[0] - '0') * 10 + (time[1] - '0');
        if (hh > 23) return 0;
    }

    if (time[3] != '?' && time[4] != '?') {
        int mm = (time[3] - '0') * 10 + (time[4] - '0');
        if (mm > 59) return 0;
    }

    if (time[0] != '?' && time[1] != '?'){
        if(time[0] > '2'){
            return 0;
        }
    }
    
    if (time[0] == '?' && time[1] == '?') {
        return 24 * (time[3] == '?' ? 6 : 1) * (time[4] == '?' ? 10 : 1);
    }
     if(time[3] == '?' && time[4] == '?') {
        if(time[0] == '?' && (time[1] >= '0' && time[1] <= '3')){
            return 3 * 60;
        }
        if(time[0] == '?' && (time[1] > '3' && time[1] <= '9')){
            return 2 * 60;
        }
        if(time[1] == '?' && (time[0] == '0' || time[0] == '1')){
            return 10 * 60;
        }
        if(time[1] == '?' && time[0] == '2'){
            return 4 * 60;
        }
    }

    int h = 1;
    if (time[0] == '?') {
        h = (time[1] <= '3') ? 3 : 2;
    } else if (time[1] == '?') {
        h = (time[0] <= '1') ? 10 : 4;
    }

    int m = 1;
    if (time[3] == '?') {
        m = 6;
    } else if (time[4] == '?') {
        m = 10;
    }

    if (time[0] != '?' && time[1] != '?') {
        int hh = (time[0] - '0') * 10 + (time[1] - '0');
       
    }

    return h * m;
}