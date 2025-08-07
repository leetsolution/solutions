class Solution:
    def maxDifference(self, s: str) -> int:
        freq = {}
        for char in s:
            freq[char] = freq.get(char, 0) + 1
        
        max_diff = -float('inf')
        
        odd_freqs = []
        even_freqs = []
        
        for char, count in freq.items():
            if count % 2 == 0:
                even_freqs.append(count)
            else:
                odd_freqs.append(count)
        
        if not odd_freqs or not even_freqs:
            return -1
        
        for odd_freq in odd_freqs:
            for even_freq in even_freqs:
                max_diff = max(max_diff, odd_freq - even_freq)
        
        return max_diff