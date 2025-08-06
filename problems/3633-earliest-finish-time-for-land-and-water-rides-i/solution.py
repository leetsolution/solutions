class Solution:
    def earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration):
        min_finish_time = float('inf')

        for i in range(len(landStartTime)):
            for j in range(len(waterStartTime)):
                # Land then Water
                land_finish = landStartTime[i] + landDuration[i]
                water_start = max(land_finish, waterStartTime[j])
                water_finish = water_start + waterDuration[j]
                min_finish_time = min(min_finish_time, water_finish)

                # Water then Land
                water_finish = waterStartTime[j] + waterDuration[j]
                land_start = max(water_finish, landStartTime[i])
                land_finish = land_start + landDuration[i]
                min_finish_time = min(min_finish_time, land_finish)

        return min_finish_time