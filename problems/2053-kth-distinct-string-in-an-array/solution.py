class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        counts = {}
        for s in arr:
            counts[s] = counts.get(s, 0) + 1
        
        distinct_strings = []
        for s in arr:
            if counts[s] == 1:
                distinct_strings.append(s)
        
        if len(distinct_strings) < k:
            return ""
        else:
            return distinct_strings[k - 1]