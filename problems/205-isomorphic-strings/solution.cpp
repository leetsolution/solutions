class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        int n = s.length();
        char s_map[256] = {0};
        char t_map[256] = {0};
        
        for (int i = 0; i < n; ++i) {
            char s_char = s[i];
            char t_char = t[i];
            
            if (s_map[s_char] == 0 && t_map[t_char] == 0) {
                s_map[s_char] = t_char;
                t_map[t_char] = s_char;
            } else {
                if (s_map[s_char] != t_char || t_map[t_char] != s_char) {
                    return false;
                }
            }
        }
        
        return true;
    }
};