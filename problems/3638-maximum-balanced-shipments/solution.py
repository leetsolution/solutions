class Solution:
    def maximum_balanced_shipments(weight):
        n = len(weight)
        count = 0
        i = 0
        while i < n:
            max_weight = 0
            j = i
            while j < n:
                max_weight = max(max_weight, weight[j])
                if weight[j] < max_weight:
                    count += 1
                    i = j + 1
                    break
                j += 1
            if j == n:
                break
        return count