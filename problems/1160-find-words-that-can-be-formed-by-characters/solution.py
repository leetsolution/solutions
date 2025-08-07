class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        char_counts = {}
        for char in chars:
            char_counts[char] = char_counts.get(char, 0) + 1
        
        total_length = 0
        for word in words:
            word_counts = {}
            is_good = True
            for char in word:
                word_counts[char] = word_counts.get(char, 0) + 1
                if char not in char_counts or word_counts[char] > char_counts[char]:
                    is_good = False
                    break
            
            if is_good:
                total_length += len(word)
        
        return total_length