class Solution:
    def maxHeightOfTriangle(self, red: int, blue: int) -> int:
        total = red + blue
        low = 0
        high = int((2 * total)**0.5)
        ans = 0
        while low <= high:
            mid = (low + high) // 2
            balls_needed = mid * (mid + 1) // 2
            if balls_needed <= total:
                temp_red = red
                curr = 0
                for i in range(1, mid + 1):
                    if (mid - i) % 2 == 0:
                        curr += i
                if curr <= red and balls_needed - curr <= blue:
                    ans = mid
                    low = mid + 1
                else:
                    high = mid - 1
            else:
                high = mid - 1
        return ans