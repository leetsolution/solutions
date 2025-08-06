class Solution:
    from collections import Counter

    def majorityElementQueries(nums, queries):
        ans = []
        for l, r, threshold in queries:
            sub_array = nums[l:r+1]
            count = Counter(sub_array)
            found = False
            for num, freq in count.items():
                if freq >= threshold:
                    ans.append(num)
                    found = True
                    break
            if not found:
                ans.append(-1)

        #Handle ties by choosing the smallest
        for i in range(len(ans)):
            if ans[i] != -1:
                l,r,threshold = queries[i]
                sub_array = nums[l:r+1]
                count = Counter(sub_array)
                max_freq = 0
                res = -1
                for num, freq in count.items():
                    if freq >= threshold:
                        if freq > max_freq:
                            max_freq = freq
                            res = num
                        elif freq == max_freq and num < res:
                            res = num

                ans[i] = res

        return ans