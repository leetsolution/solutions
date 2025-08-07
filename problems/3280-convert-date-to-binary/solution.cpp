class Solution {
public:
    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        string binaryYear = "";
        while (year > 0) {
            binaryYear = (year % 2 == 0 ? "0" : "1") + binaryYear;
            year /= 2;
        }
        string binaryMonth = "";
        while (month > 0) {
            binaryMonth = (month % 2 == 0 ? "0" : "1") + binaryMonth;
            month /= 2;
        }
        string binaryDay = "";
        while (day > 0) {
            binaryDay = (day % 2 == 0 ? "0" : "1") + binaryDay;
            day /= 2;
        }
        return binaryYear + "-" + binaryMonth + "-" + binaryDay;
    }
};