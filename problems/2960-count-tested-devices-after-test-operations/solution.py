class Solution:
    def countTestedDevices(self, batteryPercentages: list[int]) -> int:
        tested_count = 0
        for percentage in batteryPercentages:
            if percentage > tested_count:
                tested_count += 1
        return tested_count