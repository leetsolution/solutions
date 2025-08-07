class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        direction = 1
        person = 1
        for _ in range(time):
            person += direction
            if person == n + 1:
                person = n - 1
                direction = -1
            elif person == 0:
                person = 2
                direction = 1
        return person