class Solution:
    def checkDistances(self, s: str, distance: List[int]) -> bool:
        for i in range(len(s)):
            char_index = ord(s[i]) - ord('a')
            if distance[char_index] != -1:
                first_occurrence = i
                second_occurrence = s.find(s[i], i + 1)
                if second_occurrence == -1:
                    continue

                if second_occurrence - first_occurrence - 1 != distance[char_index]:
                    return False

                distance[char_index] = -1

        return True