class Solution {
    public int countDaysTogether(String arriveAlice, String leaveAlice, String arriveBob, String leaveBob) {
        int[] days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int aliceArrive = convertToDays(arriveAlice, days);
        int aliceLeave = convertToDays(leaveAlice, days);
        int bobArrive = convertToDays(arriveBob, days);
        int bobLeave = convertToDays(leaveBob, days);

        int start = Math.max(aliceArrive, bobArrive);
        int end = Math.min(aliceLeave, bobLeave);

        return Math.max(0, end - start + 1);
    }

    private int convertToDays(String date, int[] days) {
        int month = Integer.parseInt(date.substring(0, 2));
        int day = Integer.parseInt(date.substring(3, 5));

        int totalDays = 0;
        for (int i = 0; i < month - 1; i++) {
            totalDays += days[i];
        }
        totalDays += day;
        return totalDays;
    }
}