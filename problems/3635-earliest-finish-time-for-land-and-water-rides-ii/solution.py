class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        min_finish_time = float('inf')

        for i in range(len(landStartTime)):
            for j in range(len(waterStartTime)):
                # Land then Water
                land_start = landStartTime[i]
                land_finish = land_start + landDuration[i]
                water_start = max(land_finish, waterStartTime[j])
                water_finish = water_start + waterDuration[j]
                min_finish_time = min(min_finish_time, water_finish)

                # Water then Land
                water_start = waterStartTime[j]
                water_finish = water_start + waterDuration[j]
                land_start = max(water_finish, landStartTime[i])
                land_finish = land_start + landDuration[i]
                min_finish_time = min(min_finish_time, land_finish)

        return min_finish_time