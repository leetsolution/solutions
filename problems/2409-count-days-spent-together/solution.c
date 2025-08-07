int countDaysTogether(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int aliceArriveMonth = (arriveAlice[0] - '0') * 10 + (arriveAlice[1] - '0');
    int aliceArriveDay = (arriveAlice[3] - '0') * 10 + (arriveAlice[4] - '0');
    int aliceLeaveMonth = (leaveAlice[0] - '0') * 10 + (leaveAlice[1] - '0');
    int aliceLeaveDay = (leaveAlice[3] - '0') * 10 + (leaveAlice[4] - '0');

    int bobArriveMonth = (arriveBob[0] - '0') * 10 + (arriveBob[1] - '0');
    int bobArriveDay = (arriveBob[3] - '0') * 10 + (arriveBob[4] - '0');
    int bobLeaveMonth = (leaveBob[0] - '0') * 10 + (leaveBob[1] - '0');
    int bobLeaveDay = (leaveBob[3] - '0') * 10 + (leaveBob[4] - '0');

    int aliceArriveTotalDays = 0;
    for (int i = 0; i < aliceArriveMonth - 1; i++) {
        aliceArriveTotalDays += daysInMonth[i];
    }
    aliceArriveTotalDays += aliceArriveDay;

    int aliceLeaveTotalDays = 0;
    for (int i = 0; i < aliceLeaveMonth - 1; i++) {
        aliceLeaveTotalDays += daysInMonth[i];
    }
    aliceLeaveTotalDays += aliceLeaveDay;

    int bobArriveTotalDays = 0;
    for (int i = 0; i < bobArriveMonth - 1; i++) {
        bobArriveTotalDays += daysInMonth[i];
    }
    bobArriveTotalDays += bobArriveDay;

    int bobLeaveTotalDays = 0;
    for (int i = 0; i < bobLeaveMonth - 1; i++) {
        bobLeaveTotalDays += daysInMonth[i];
    }
    bobLeaveTotalDays += bobLeaveDay;

    int start = (aliceArriveTotalDays > bobArriveTotalDays) ? aliceArriveTotalDays : bobArriveTotalDays;
    int end = (aliceLeaveTotalDays < bobLeaveTotalDays) ? aliceLeaveTotalDays : bobLeaveTotalDays;

    if (start > end) {
        return 0;
    }

    return end - start + 1;
}