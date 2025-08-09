class Solution {
public:
    long long numOfSubsequences(string s) {
        long long ans = 0;
        long long l = 0;
        long long lc = 0;
        long long lct = 0;
        for (char c : s) {
            if (c == 'L') {
                l++;
                ans = max(ans, lc + lct);
            } else if (c == 'C') {
                lc += l;
                ans = max(ans, lc + lct);
            } else if (c == 'T') {
                lct += lc;
                ans = max(ans, lc + lct);
            }
        }
        
        long long max_ans = lct;
        
        l = 0;
        lc = 0;
        lct = 0;
        for (char c : s) {
            if (c == 'L') {
                long long temp_lct = lct;
                long long temp_lc = lc;
                long long temp_l = l;
                
                max_ans = max(max_ans, (lc + lct));
                
                l++;
                
                lct = temp_lct;
                lc = temp_lc;
                l = temp_l;

            } else if (c == 'C') {
                long long temp_lct = lct;
                long long temp_lc = lc;
                long long temp_l = l;
                
                lc += l;
                max_ans = max(max_ans, lc + lct);
                lct = temp_lct;
                lc = temp_lc;
                l = temp_l;

                
            } else if (c == 'T') {
                long long temp_lct = lct;
                long long temp_lc = lc;
                long long temp_l = l;

                lct += lc;
                max_ans = max(max_ans, lc + lct);

                lct = temp_lct;
                lc = temp_lc;
                l = temp_l;

            }
        
             if (c == 'L') {
                l++;
            } else if (c == 'C') {
                lc += l;
            } else if (c == 'T') {
                lct += lc;
            }
        }

        l = 0;
        lc = 0;
        lct = 0;
        for (char c : s) {
           if (c == 'L') {
                l++;
            } else if (c == 'C') {
                lc += l;
            } else if (c == 'T') {
                lct += lc;
            }
        }
        max_ans = max(max_ans, lct);
        
        
         l = 0;
         lc = 0;
         lct = 0;
        long long tempL =0, tempLC=0, tempLCT =0;
                
        for (int i = 0; i < s.size(); ++i)
        {
             if (s[i] == 'L')
             {
                 tempL++;
             }else if (s[i] == 'C')
             {
                 tempLC += tempL;
             }else{
                 tempLCT += tempLC;
             }
             
        }
        max_ans = max(max_ans, tempLCT);
        

        
        l = 0;
        lc = 0;
        lct = 0;
        for (char c : s) {
           if (c == 'L') {
                l++;
            } else if (c == 'C') {
                lc += l;
            } else if (c == 'T') {
                lct += lc;
            }
        }
        
        
        return max_ans;
    }
};