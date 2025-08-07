char* reformatDate(char* date) {
    char* day = (char*)malloc(3 * sizeof(char));
    char* month = (char*)malloc(4 * sizeof(char));
    char* year = (char*)malloc(5 * sizeof(char));
    char* result = (char*)malloc(11 * sizeof(char));

    sscanf(date, "%[^ ] %[^ ] %[^ ]", day, month, year);

    int day_int = 0;
    if (day[1] >= '0' && day[1] <= '9') {
        day_int = (day[0] - '0') * 10 + (day[1] - '0');
    } else {
        day_int = day[0] - '0';
    }
    
    int month_int = 0;
    if (strcmp(month, "Jan") == 0) month_int = 1;
    else if (strcmp(month, "Feb") == 0) month_int = 2;
    else if (strcmp(month, "Mar") == 0) month_int = 3;
    else if (strcmp(month, "Apr") == 0) month_int = 4;
    else if (strcmp(month, "May") == 0) month_int = 5;
    else if (strcmp(month, "Jun") == 0) month_int = 6;
    else if (strcmp(month, "Jul") == 0) month_int = 7;
    else if (strcmp(month, "Aug") == 0) month_int = 8;
    else if (strcmp(month, "Sep") == 0) month_int = 9;
    else if (strcmp(month, "Oct") == 0) month_int = 10;
    else if (strcmp(month, "Nov") == 0) month_int = 11;
    else if (strcmp(month, "Dec") == 0) month_int = 12;

    sprintf(result, "%s-%02d-%02d", year, month_int, day_int);

    free(day);
    free(month);
    free(year);

    return result;
}