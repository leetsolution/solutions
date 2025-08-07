int daysBetweenDates(char* date1, char* date2) {
    int year1, month1, day1, year2, month2, day2;
    sscanf(date1, "%d-%d-%d", &year1, &month1, &day1);
    sscanf(date2, "%d-%d-%d", &year2, &month2, &day2);

    int days1 = 0;
    for (int i = 1971; i < year1; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            days1 += 366;
        } else {
            days1 += 365;
        }
    }
    int daysInMonth1[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0)) {
        daysInMonth1[2] = 29;
    }
    for (int i = 1; i < month1; i++) {
        days1 += daysInMonth1[i];
    }
    days1 += day1;

    int days2 = 0;
    for (int i = 1971; i < year2; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            days2 += 366;
        } else {
            days2 += 365;
        }
    }
    int daysInMonth2[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0)) {
        daysInMonth2[2] = 29;
    }
    for (int i = 1; i < month2; i++) {
        days2 += daysInMonth2[i];
    }
    days2 += day2;

    return abs(days1 - days2);
}