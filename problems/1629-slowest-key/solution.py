class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        max_duration = releaseTimes[0]
        slowest_key = keysPressed[0]

        for i in range(1, len(releaseTimes)):
            duration = releaseTimes[i] - releaseTimes[i-1]
            if duration > max_duration:
                max_duration = duration
                slowest_key = keysPressed[i]
            elif duration == max_duration:
                if keysPressed[i] > slowest_key:
                    slowest_key = keysPressed[i]

        return slowest_key