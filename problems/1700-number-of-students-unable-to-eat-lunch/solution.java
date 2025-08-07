class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int unableToEat = 0;
        int studentIndex = 0;
        int sandwichIndex = 0;
        int n = students.length;

        while (unableToEat < n && sandwichIndex < n) {
            if (students[studentIndex % n] == sandwiches[sandwichIndex]) {
                unableToEat = 0;
                sandwichIndex++;
                students[studentIndex % n] = -1; 
            } else {
                unableToEat++;
            }
            studentIndex++;
        }

        int count = 0;
        for (int student : students) {
            if (student != -1) {
                count++;
            }
        }

        return count - (n - sandwichIndex);
    }
}