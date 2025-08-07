#include <stdlib.h>
#include <string.h>

char* convertDateToBinary(char* date) {
    char year[5], month[3], day[3];
    strncpy(year, date, 4);
    year[4] = '\0';
    strncpy(month, date + 5, 2);
    month[2] = '\0';
    strncpy(day, date + 8, 2);
    day[2] = '\0';

    int year_int = atoi(year);
    int month_int = atoi(month);
    int day_int = atoi(day);

    char* year_bin = (char*)malloc(33);
    char* month_bin = (char*)malloc(5);
    char* day_bin = (char*)malloc(6);

    int i;
    for (i = 16; i >= 0; i--) {
        year_bin[16-i] = ((year_int >> i) & 1) ? '1' : '0';
    }
    year_bin[17] = '\0';
    
    for (i = 3; i >=0; i--){
        month_bin[3-i] = ((month_int >> i) & 1) ? '1' : '0';
    }
    month_bin[4] = '\0';

    for (i = 4; i >=0; i--){
        day_bin[4-i] = ((day_int >> i) & 1) ? '1' : '0';
    }
    day_bin[5] = '\0';


    char* result = (char*)malloc(strlen(year_bin) + strlen(month_bin) + strlen(day_bin) + 3);
    sprintf(result, "%s-%s-%s", year_bin, month_bin, day_bin);

    free(year_bin);
    free(month_bin);
    free(day_bin);
    return result;
}