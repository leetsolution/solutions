class Solution:
    def countPoints(self, rings: str) -> int:
        rods = [set() for _ in range(10)]
        for i in range(0, len(rings), 2):
            color = rings[i]
            rod_num = int(rings[i+1])
            rods[rod_num].add(color)
        count = 0
        for rod in rods:
            if len(rod) == 3:
                count += 1
        return count