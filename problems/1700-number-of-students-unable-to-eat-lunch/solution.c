int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int unableToEat = 0;
    int i = 0;

    while (unableToEat < studentsSize) {
        if (students[0] == sandwiches[0]) {
            for (int j = 0; j < studentsSize - 1; j++) {
                students[j] = students[j + 1];
            }
            studentsSize--;
            for (int j = 0; j < sandwichesSize - 1; j++) {
                sandwiches[j] = sandwiches[j + 1];
            }
            sandwichesSize--;
            unableToEat = 0;
        } else {
            int temp = students[0];
            for (int j = 0; j < studentsSize - 1; j++) {
                students[j] = students[j + 1];
            }
            students[studentsSize - 1] = temp;
            unableToEat++;
        }
    }

    return studentsSize;
}