class Solution:
    def partitionString(self, s: str) -> List[str]:
        segments = []
        seen = set()
        current_segment = ""
        for i in range(len(s)):
            current_segment += s[i]
            if current_segment in seen:
                current_segment = s[i]
            segments.append(current_segment)
            seen.add(current_segment)
            current_segment = ""
        return segments