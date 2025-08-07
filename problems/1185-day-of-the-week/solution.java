class Solution {
    public String dayOfTheWeek(int day, int month, int year) {
        String[] days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        int[] months = {0, 3, 2, 3, 2, 3, 2, 3, 3, 2, 3, 2};
        if (month < 3) {
            month += 12;
            year -= 1;
        }
        int k = year % 100;
        int j = year / 100;
        int dayIndex = (day + months[month - 1] + k + k / 4 + j / 4 - 2 * j) % 7;
        if (dayIndex < 0) {
            dayIndex += 7;
        }
        return days[dayIndex];
    }
}