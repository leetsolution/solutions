long long numOfSubsequences(char* s) {
    long long ans = 0;
    long long l = 0;
    long long lc = 0;
    long long lct = 0;
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            l++;
        } else if (s[i] == 'C') {
            lc += l;
        } else if (s[i] == 'T') {
            lct += lc;
        }
    }

    ans = lct;

    l = 0;
    lc = 0;
    lct = 0;

    long long max_ans = ans;

    for (int i = 0; i <= n; i++) {
        long long cur_l = 0;
        long long cur_lc = 0;
        long long cur_lct = 0;

        l = 0;
        lc = 0;
        lct = 0;

        for (int j = 0; j < i; j++) {
            if (s[j] == 'L') {
                l++;
            } else if (s[j] == 'C') {
                lc += l;
            } else if (s[j] == 'T') {
                lct += lc;
            }
        }
        cur_l = l;
        cur_lc = lc;
        cur_lct = lct;

        if(i<n){
           l = 0;
           lc = 0;
           lct = 0;

           for (int j = i; j < n; j++) {
                if (s[j] == 'L') {
                    l++;
                } else if (s[j] == 'C') {
                    lc += l;
                } else if (s[j] == 'T') {
                    lct += lc;
                }
            }
        }

        long long suffix_l = l;
        long long suffix_lc = lc;
        long long suffix_lct = lct;

        l = 0;
        lc = 0;
        lct = 0;

        if (i>0){
            l = 0;
            lc = 0;
            lct = 0;
            for (int j = 0; j < i; j++) {
                if (s[j] == 'L') {
                    l++;
                } else if (s[j] == 'C') {
                    lc += l;
                } else if (s[j] == 'T') {
                    lct += lc;
                }
            }
        }

        cur_l = l;
        cur_lc = lc;
        cur_lct = lct;


        if (i >0){
             l = 0;
             lc = 0;
             lct = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == 'L') {
                    l++;
                } else if (s[j] == 'C') {
                    lc += l;
                } else if (s[j] == 'T') {
                    lct += lc;
                }
            }
        }

        suffix_l = l;
        suffix_lc = lc;
        suffix_lct = lct;

        long long temp_ans = 0;

        
        temp_ans = cur_lct + cur_lc + suffix_lct + suffix_lc*cur_l + suffix_l*cur_lc;

        max_ans = (max_ans > temp_ans) ? max_ans : temp_ans;
        

        l = 0;
        lc = 0;
        lct = 0;

        if (i>0){
            l = 0;
            lc = 0;
            lct = 0;
            for (int j = 0; j < i; j++) {
                if (s[j] == 'L') {
                    l++;
                } else if (s[j] == 'C') {
                    lc += l;
                } else if (s[j] == 'T') {
                    lct += lc;
                }
            }
        }

        cur_l = l;
        cur_lc = lc;
        cur_lct = lct;

        if (i >0){
             l = 0;
             lc = 0;
             lct = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == 'L') {
                    l++;
                } else if (s[j] == 'C') {
                    lc += l;
                } else if (s[j] == 'T') {
                    lct += lc;
                }
            }
        }

        suffix_l = l;
        suffix_lc = lc;
        suffix_lct = lct;
         temp_ans = 0;

        
        temp_ans = cur_lct + suffix_lct + suffix_l*cur_c + cur_l*suffix_c;
        if (s[i-1]=='C'){
            
        }else {
           
        }

        l = 0;
        lc = 0;
        lct = 0;

        if (i>0){
            l = 0;
            lc = 0;
            lct = 0;
            for (int j = 0; j < i; j++) {
                if (s[j] == 'L') {
                    l++;
                } else if (s[j] == 'C') {
                    lc += l;
                } else if (s[j] == 'T') {
                    lct += lc;
                }
            }
        }

        cur_l = l;
        cur_lc = lc;
        cur_lct = lct;

        if (i >0){
             l = 0;
             lc = 0;
             lct = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == 'L') {
                    l++;
                } else if (s[j] == 'C') {
                    lc += l;
                } else if (s[j] == 'T') {
                    lct += lc;
                }
            }
        }

        suffix_l = l;
        suffix_lc = lc;
        suffix_lct = lct;
        temp_ans = 0;

      
        temp_ans = cur_lct + cur_lc*suffix_t + suffix_lct + suffix_lc;

        }


    l = 0;
    lc = 0;
    lct = 0;

    return max_ans;
}