class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;
        for (string op : operations) {
            if (op == "+") {
                int sum = record[record.size() - 1] + record[record.size() - 2];
                record.push_back(sum);
            } else if (op == "D") {
                record.push_back(record[record.size() - 1] * 2);
            } else if (op == "C") {
                record.pop_back();
            } else {
                record.push_back(stoi(op));
            }
        }
        int sum = 0;
        for (int score : record) {
            sum += score;
        }
        return sum;
    }
};