class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int unableToEat = 0;
        int studentIndex = 0;
        int sandwichIndex = 0;
        int n = students.size();
        while (unableToEat < n && sandwichIndex < n) {
            if (students[studentIndex % n] == sandwiches[sandwichIndex]) {
                unableToEat = 0;
                studentIndex++;
                sandwichIndex++;
            } else {
                unableToEat++;
                studentIndex++;
            }
        }
        return n - sandwichIndex;
    }
};