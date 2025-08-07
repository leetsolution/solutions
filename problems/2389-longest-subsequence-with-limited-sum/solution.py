class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        m = len(queries)
        answer = []
        for q in queries:
            count = 0
            current_sum = 0
            for i in range(n):
                if current_sum + nums[i] <= q:
                    current_sum += nums[i]
                    count += 1
                else:
                    break
            answer.append(count)
        return answer