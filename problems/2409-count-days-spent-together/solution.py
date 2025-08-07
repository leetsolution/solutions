class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        def to_days(date):
            month, day = map(int, date.split('-'))
            days_in_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
            days = 0
            for i in range(month - 1):
                days += days_in_month[i]
            days += day
            return days

        alice_arrive = to_days(arriveAlice)
        alice_leave = to_days(leaveAlice)
        bob_arrive = to_days(arriveBob)
        bob_leave = to_days(leaveBob)

        start = max(alice_arrive, bob_arrive)
        end = min(alice_leave, bob_leave)

        if start > end:
            return 0
        else:
            return end - start + 1