class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ans = [0] * num_people
        i = 0
        candy_to_give = 1
        while candies > 0:
            ans[i % num_people] += min(candies, candy_to_give)
            candies -= candy_to_give
            candy_to_give += 1
            i += 1
        return ans