class Solution:
    def minDeletion(self, s: str, k: int) -> int:
        counts = {}
        for char in s:
            counts[char] = counts.get(char, 0) + 1
        
        freqs = sorted(counts.values())
        
        if len(counts) <= k:
            return 0
        
        deletions = 0
        
        while len(counts) > k:
            deletions += freqs.pop(0)
            counts = {}
            new_s = s
            
            for char, count in counts.items():
                
                new_counts = {}
                for c in new_s:
                    new_counts[c] = new_counts.get(c, 0) +1
            
            
            
            counts = {}
            for char in s:
                counts[char] = counts.get(char, 0) + 1
            
            freqs = sorted(counts.values())
            
            while len(freqs) > 0 and freqs[0] == 0:
                freqs.pop(0)

            counts = {}
            for char in s:
                counts[char] = counts.get(char, 0) + 1

            valid_chars = []
            for char, count in counts.items():
                if count > 0:
                    valid_chars.append(char)
            
            new_counts = {}
            for c in s:
                new_counts[c] = new_counts.get(c, 0) +1
            
            
            counts = {}
            for char in s:
                counts[char] = counts.get(char, 0) + 1
            
            freqs = sorted(counts.values())

            counts = {}
            for char in s:
                counts[char] = counts.get(char, 0) + 1
            
            freqs = sorted(counts.values())
            temp_counts = {}

        temp_counts = {}
        for char in s:
            temp_counts[char] = temp_counts.get(char, 0) + 1

        counts = {}

        for key in temp_counts:
            if temp_counts[key] > 0:
                counts[key] = temp_counts[key]

        if len(counts) <= k:
            return deletions

        
        frequencies = sorted(counts.values())
        
        
        while len(counts) > k:
            min_freq = frequencies[0]
            
            deleted_char = ""
            for char, freq in counts.items():
                if freq == min_freq:
                    deleted_char = char
                    break
            
            deletions += min_freq
            del counts[deleted_char]
            
            frequencies.pop(0)
            
            frequencies = sorted(counts.values())

        return deletions