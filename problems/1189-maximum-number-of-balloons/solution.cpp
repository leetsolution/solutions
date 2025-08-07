class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int count[26] = {0};
        for (char c : text) {
            count[c - 'a']++;
        }
        int min_balloons = INT_MAX;
        min_balloons = min(min_balloons, count[0]);
        min_balloons = min(min_balloons, count[1]);
        min_balloons = min(min_balloons, count[11] / 2);
        min_balloons = min(min_balloons, count[14] / 2);
        min_balloons = min(min_balloons, count[13]);
        return min_balloons == INT_MAX ? 0 : min_balloons;
    }
};