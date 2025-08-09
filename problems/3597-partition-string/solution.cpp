class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string> segments;
        unordered_set<string> seen;
        int n = s.length();
        int start = 0;
        while (start < n) {
            string current_segment = "";
            int current_index = start;
            while (current_index < n) {
                current_segment += s[current_index];
                if (seen.find(current_segment) == seen.end()) {
                    segments.push_back(current_segment);
                    seen.insert(current_segment);
                    start = current_index + 1;
                    break;
                } else {
                    current_index++;
                }
            }
            if (current_index == n && start != n) {
                string temp = "";
                 while (start < n) {
                     temp+= s[start];
                     start++;
                 }
                segments.push_back(temp);
                break;
            }
        }
        return segments;
    }
};