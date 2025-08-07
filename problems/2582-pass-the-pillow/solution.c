int passThePillow(int n, int time) {
    int direction = 1;
    int person = 1;
    for (int i = 0; i < time; i++) {
        person += direction;
        if (person == n + 1) {
            person = n - 1;
            direction = -1;
        } else if (person == 0) {
            person = 2;
            direction = 1;
        }
    }
    return person;
}