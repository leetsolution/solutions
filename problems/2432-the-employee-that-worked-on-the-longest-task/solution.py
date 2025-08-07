class Solution:
    def hardestWorker(self, n: int, logs: List[List[int]]) -> int:
        max_time = logs[0][1]
        employee_id = logs[0][0]
        start_time = 0
        for log in logs:
            current_time = log[1] - start_time
            if current_time > max_time:
                max_time = current_time
                employee_id = log[0]
            elif current_time == max_time:
                employee_id = min(employee_id, log[0])
            start_time = log[1]
        return employee_id