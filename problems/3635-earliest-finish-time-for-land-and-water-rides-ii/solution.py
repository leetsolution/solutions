class Solution:
    def earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration):
        ans = float('inf')
        for i in range(len(landStartTime)):
            for j in range(len(waterStartTime)):
                # Land then Water
                land_end = landStartTime[i] + landDuration[i]
                water_end = max(land_end, waterStartTime[j]) + waterDuration[j]
                ans = min(ans, water_end)
                # Water then Land
                water_end = waterStartTime[j] + waterDuration[j]
                land_end = max(water_end, landStartTime[i]) + landDuration[i]
                ans = min(ans, land_end)
        return ans