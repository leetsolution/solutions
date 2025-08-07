class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> months = {
            {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"},
            {"Apr", "04"}, {"May", "05"}, {"Jun", "06"},
            {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"},
            {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
        };
        string year = date.substr(date.size() - 4, 4);
        string month = months[date.substr(date.size() - 8, 3)];
        string day = date.substr(0, date.find('t'));
        if (day.size() == 1) {
            day = "0" + day;
        }
        return year + "-" + month + "-" + day;
    }
};