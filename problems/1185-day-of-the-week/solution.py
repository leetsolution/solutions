class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        days = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"]
        d = day
        m = month
        y = year
        if m < 3:
            m += 12
            y -= 1
        c = y // 100
        yr = y % 100
        w = (d + ((13 * (m + 1)) // 5) + yr + (yr // 4) + (c // 4) - (2 * c)) % 7
        return days[w]