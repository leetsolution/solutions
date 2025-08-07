class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        box_counts = {}
        for i in range(lowLimit, highLimit + 1):
            s = sum(int(digit) for digit in str(i))
            if s in box_counts:
                box_counts[s] += 1
            else:
                box_counts[s] = 1
        
        max_balls = 0
        for count in box_counts.values():
            if count > max_balls:
                max_balls = count
        
        return max_balls