class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int max_time = logs[0][1];
        int worker_id = logs[0][0];
        int prev_time = 0;
        for (int i = 0; i < logs.size(); i++) {
            int current_time = logs[i][1] - prev_time;
            if (current_time > max_time) {
                max_time = current_time;
                worker_id = logs[i][0];
            } else if (current_time == max_time && logs[i][0] < worker_id) {
                worker_id = logs[i][0];
            }
            prev_time = logs[i][1];
        }
        return worker_id;
    }
};