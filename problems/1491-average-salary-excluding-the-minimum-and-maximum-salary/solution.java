class Solution {
    public double average(int[] salary) {
        int minSalary = salary[0];
        int maxSalary = salary[0];
        double sum = 0;

        for (int s : salary) {
            minSalary = Math.min(minSalary, s);
            maxSalary = Math.max(maxSalary, s);
            sum += s;
        }

        sum -= minSalary + maxSalary;
        return sum / (salary.length - 2);
    }
}