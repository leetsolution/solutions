class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto convertToDays = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            int totalDays = 0;
            for (int i = 1; i < month; ++i) {
                totalDays += days[i - 1];
            }
            totalDays += day;
            return totalDays;
        };

        int arriveAliceDays = convertToDays(arriveAlice);
        int leaveAliceDays = convertToDays(leaveAlice);
        int arriveBobDays = convertToDays(arriveBob);
        int leaveBobDays = convertToDays(leaveBob);

        int start = max(arriveAliceDays, arriveBobDays);
        int end = min(leaveAliceDays, leaveBobDays);

        return max(0, end - start + 1);
    }
};