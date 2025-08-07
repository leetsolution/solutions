class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        n = len(fruits)
        placed = [False] * n
        basket_used = [False] * n

        for i in range(n):
            best_basket = -1
            min_index = float('inf')

            for j in range(n):
                if not basket_used[j] and baskets[j] >= fruits[i] and j < min_index:
                    best_basket = j
                    min_index = j

            if best_basket != -1:
                basket_used[best_basket] = True
                placed[i] = True

        unplaced_count = 0
        for p in placed:
            if not p:
                unplaced_count += 1

        return unplaced_count