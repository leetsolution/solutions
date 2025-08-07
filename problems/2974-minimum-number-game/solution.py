class Solution:
    def numberGame(self, nums: list[int]) -> list[int]:
        """
        Solves the Minimum Number Game problem.

        The method first sorts the array `nums` in ascending order. This places the
        smallest elements, which Alice and Bob would pick, next to each other in pairs.
        For each pair of elements at indices `i` and `i+1` in the sorted array,
        `nums[i]` is the element Alice picks, and `nums[i+1]` is the element Bob picks.

        According to the rules, Bob appends his number first, followed by Alice's.
        This means for each pair `(nums[i], nums[i+1])`, they should appear in the
        result as `(nums[i+1], nums[i])`.

        This can be achieved by iterating through the sorted array with a step of 2
        and swapping the elements in each pair. The modified `nums` array will then
        be the required result `arr`.

        Example: nums = [5, 4, 2, 3]
        1. Sort nums: [2, 3, 4, 5]
        2. Iterate and swap pairs:
           - i = 0: swap nums[0] (2) and nums[1] (3) -> [3, 2, 4, 5]
           - i = 2: swap nums[2] (4) and nums[3] (5) -> [3, 2, 5, 4]
        3. Return the modified list: [3, 2, 5, 4]
        """
        nums.sort()
        for i in range(0, len(nums), 2):
            nums[i], nums[i+1] = nums[i+1], nums[i]
        return nums