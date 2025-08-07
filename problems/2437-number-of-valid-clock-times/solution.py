class Solution:
    def countTime(self, time: str) -> int:
        h = time[:2]
        m = time[3:]
        h_count = 0
        m_count = 0

        if h == "??":
            h_count = 24
        elif h[0] == "?" and h[1] != "?":
            if int(h[1]) <= 3:
                h_count = 3
            else:
                h_count = 2
        elif h[0] != "?" and h[1] == "?":
            if int(h[0]) == 0 or int(h[0]) == 1:
                h_count = 10
            else:
                h_count = 4
        else:
            h_count = 1

        if m == "??":
            m_count = 60
        elif m[0] == "?" and m[1] != "?":
            m_count = 6
        elif m[0] != "?" and m[1] == "?":
            m_count = 10
        else:
            m_count = 1

        return h_count * m_count