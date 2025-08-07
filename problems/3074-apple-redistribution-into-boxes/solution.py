class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        total_apples = sum(apple)
        capacity.sort(reverse=True)
        count = 0
        current_capacity = 0
        for c in capacity:
            current_capacity += c
            count += 1
            if current_capacity >= total_apples:
                return count
        return count