int convertTime(char* current, char* correct) {
    int current_hour = (current[0] - '0') * 10 + (current[1] - '0');
    int current_minute = (current[3] - '0') * 10 + (current[4] - '0');
    int correct_hour = (correct[0] - '0') * 10 + (correct[1] - '0');
    int correct_minute = (correct[3] - '0') * 10 + (correct[4] - '0');

    int current_total_minutes = current_hour * 60 + current_minute;
    int correct_total_minutes = correct_hour * 60 + correct_minute;

    int diff = correct_total_minutes - current_total_minutes;
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