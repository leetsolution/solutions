double average(int* salary, int salarySize) {
    int minSalary = salary[0];
    int maxSalary = salary[0];
    double sum = 0;

    for (int i = 0; i < salarySize; i++) {
        if (salary[i] < minSalary) {
            minSalary = salary[i];
        }
        if (salary[i] > maxSalary) {
            maxSalary = salary[i];
        }
        sum += salary[i];
    }

    sum -= (minSalary + maxSalary);
    return sum / (salarySize - 2);
}