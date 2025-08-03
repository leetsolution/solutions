class Solution:
    def earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration):
        ans = float('inf')
        for i in range(len(landStartTime)):
            for j in range(len(waterStartTime)):
                # Land then Water
                finish_time_lw = landStartTime[i] + landDuration[i]
                start_time_w = max(finish_time_lw, waterStartTime[j])
                finish_time_lw = start_time_w + waterDuration[j]
                ans = min(ans, finish_time_lw)

                # Water then Land
                finish_time_wl = waterStartTime[j] + waterDuration[j]
                start_time_l = max(finish_time_wl, landStartTime[i])
                finish_time_wl = start_time_l + landDuration[i]
                ans = min(ans, finish_time_wl)
        return ans