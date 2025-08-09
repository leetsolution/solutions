class Solution:
    def minTime(self, n: int, edges: List[List[int]], k: int) -> int:
        if k <= 1:
            return 0 if n == 1 else max(edge[2] for edge in edges) if edges else 0

        def count_components(time):
            parent = list(range(n))

            def find(i):
                if parent[i] == i:
                    return i
                parent[i] = find(parent[i])
                return parent[i]

            def union(i, j):
                root_i = find(i)
                root_j = find(j)
                if root_i != root_j:
                    parent[root_i] = root_j

            for u, v, t in edges:
                if t > time:
                    union(u, v)

            components = set()
            for i in range(n):
                components.add(find(i))
            return len(components)

        if count_components(0) >= k:
            return 0

        times = sorted(list(set([edge[2] for edge in edges])))
        
        left, right = 0, len(times) - 1
        ans = 0
        
        while left <= right:
            mid = (left + right) // 2
            time = times[mid]
            
            if count_components(time) >= k:
                ans = time
                right = mid - 1
            else:
                left = mid + 1
        
        return ans