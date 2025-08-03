class Solution:
    def countSetBits(n):
        count = 0
        while (n > 0):
            n &= (n - 1)
            count += 1
        return count

    def popcount_depth(x):
        depth = 0
        while x != 1:
            x = countSetBits(x)
            depth += 1
        return depth

    def solve():
        nums = list(map(int, input().split(',')))
        queries_str = input()
        queries_str = queries_str[1:-1]
        queries_list = []
        if len(queries_str)>0:
            query_strs = queries_str.split('],[')
            for q in query_strs:
                query = list(map(int, q.split(',')))
                queries_list.append(query)


        answer = []
        for query in queries_list:
            if query[0] == 1:
                l, r, k = query[1], query[2], query[3]
                count = 0
                for i in range(l, r + 1):
                    if popcount_depth(nums[i]) == k:
                        count += 1
                answer.append(count)
            else:
                idx, val = query[1], query[2]
                nums[idx] = val

        print(answer)

    solve()