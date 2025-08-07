class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        def is_leap(year):
            return (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)

        def days_in_year(year):
            return 366 if is_leap(year) else 365

        def days_in_month(year, month):
            if month in [4, 6, 9, 11]:
                return 30
            elif month == 2:
                return 29 if is_leap(year) else 28
            else:
                return 31

        def days_from_1971(date):
            year, month, day = map(int, date.split('-'))
            days = 0
            for y in range(1971, year):
                days += days_in_year(y)
            for m in range(1, month):
                days += days_in_month(year, m)
            days += day
            return days

        return abs(days_from_1971(date1) - days_from_1971(date2))