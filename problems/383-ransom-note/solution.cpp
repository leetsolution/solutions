class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> ransomCount;
        map<char, int> magazineCount;

        for (char c : ransomNote) {
            ransomCount[c]++;
        }

        for (char c : magazine) {
            magazineCount[c]++;
        }

        for (auto const& [key, val] : ransomCount) {
            if (magazineCount.count(key) == 0 || magazineCount[key] < val) {
                return false;
            }
        }

        return true;
    }
};