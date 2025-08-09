class Solution:
    def minIncrease(self, n: int, edges: List[List[int]], cost: List[int]) -> int:
        graph = [[] for _ in range(n)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        leaves = []

        def dfs(node, parent, path_sum):
            is_leaf = True
            for neighbor in graph[node]:
                if neighbor != parent:
                    is_leaf = False
                    dfs(neighbor, node, path_sum + cost[neighbor])
            if is_leaf:
                leaves.append(path_sum)

        dfs(0, -1, cost[0])

        if not leaves:
            return 0

        max_path_sum = max(leaves)
        ans = 0
        for path_sum in leaves:
            ans += max_path_sum - path_sum
        
        increases = {}
        
        def dfs2(node, parent, path_sum, increase_count):
            is_leaf = True
            for neighbor in graph[node]:
                if neighbor != parent:
                    is_leaf = False
                    dfs2(neighbor, node, path_sum + cost[neighbor], increase_count)
            if is_leaf:
                return
            
            
        
        return ans // (max_path_sum - min(leaves)) if max_path_sum != min(leaves) else 0