class Solution {
public:
    int convertTime(string current, string correct) {
        int current_hour = stoi(current.substr(0, 2));
        int current_minute = stoi(current.substr(3, 2));
        int correct_hour = stoi(correct.substr(0, 2));
        int correct_minute = stoi(correct.substr(3, 2));

        int diff = (correct_hour - current_hour) * 60 + (correct_minute - current_minute);
        if (diff < 0) {
            diff += 24 * 60;
        }

        int operations = 0;
        operations += diff / 60;
        diff %= 60;
        operations += diff / 15;
        diff %= 15;
        operations += diff / 5;
        diff %= 5;
        operations += diff;

        return operations;
    }
};