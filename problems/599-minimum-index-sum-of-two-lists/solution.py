class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        dict1 = {}
        for i, item in enumerate(list1):
            dict1[item] = i
        min_sum = float('inf')
        res = []
        for i, item in enumerate(list2):
            if item in dict1:
                curr_sum = i + dict1[item]
                if curr_sum < min_sum:
                    min_sum = curr_sum
                    res = [item]
                elif curr_sum == min_sum:
                    res.append(item)
        return res