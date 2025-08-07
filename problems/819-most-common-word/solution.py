class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        import re
        from collections import Counter
        words = re.findall(r'\b\w+\b', paragraph.lower())
        banned_set = set(banned)
        word_counts = Counter(word for word in words if word not in banned_set)
        return word_counts.most_common(1)[0][0]