class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        first_word_counts = {}
        for char in words[0]:
            first_word_counts[char] = first_word_counts.get(char, 0) + 1
        
        result = []
        for char in first_word_counts:
            min_count = first_word_counts[char]
            for i in range(1, len(words)):
                count = words[i].count(char)
                min_count = min(min_count, count)
            
            for _ in range(min_count):
                result.append(char)
        
        return result