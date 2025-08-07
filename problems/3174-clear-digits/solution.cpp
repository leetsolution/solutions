class Solution {
public:
    string clearDigits(string s) {
        while (true) {
            bool found = false;
            for (int i = 0; i < s.length(); ++i) {
                if (isdigit(s[i])) {
                    bool has_left = false;
                    for(int j = i - 1; j >= 0; j--){
                        if(!isdigit(s[j])){
                            has_left = true;
                            s.erase(j, 1);
                            s.erase(i - (j < i), 1);
                            found = true;
                            break;
                        }
                    }
                    if(found) break;
                }
            }
            if (!found) break;
        }
        return s;
    }
};