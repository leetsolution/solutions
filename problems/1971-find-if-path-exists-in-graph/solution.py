class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        if source == destination:
            return True

        graph = [[] for _ in range(n)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        visited = [False] * n
        queue = [source]
        visited[source] = True

        while queue:
            u = queue.pop(0)
            for v in graph[u]:
                if not visited[v]:
                    if v == destination:
                        return True
                    visited[v] = True
                    queue.append(v)

        return False