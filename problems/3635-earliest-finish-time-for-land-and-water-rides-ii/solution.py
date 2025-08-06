class Solution:
    def earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration):
        ans = float('inf')
        for i in range(len(landStartTime)):
            for j in range(len(waterStartTime)):
                # Land then Water
                land_finish = landStartTime[i] + landDuration[i]
                water_finish = max(land_finish, waterStartTime[j]) + waterDuration[j]
                ans = min(ans, water_finish)

                # Water then Land
                water_finish = waterStartTime[j] + waterDuration[j]
                land_finish = max(water_finish, landStartTime[i]) + landDuration[i]
                ans = min(ans, land_finish)
        return ans