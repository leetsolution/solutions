bool isPerfectSquare(int num) {
    long long i = 1;
    while (i * i < num) {
        i++;
    }
    return i * i == num;
}