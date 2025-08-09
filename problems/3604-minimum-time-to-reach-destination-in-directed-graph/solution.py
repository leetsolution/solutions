import heapq

class Solution:
    def minTime(self, n: int, edges: List[List[int]]) -> int:
        graph = [[] for _ in range(n)]
        for u, v, start, end in edges:
            graph[u].append((v, start, end))

        dist = [float('inf')] * n
        dist[0] = 0
        pq = [(0, 0)]

        while pq:
            time, node = heapq.heappop(pq)

            if time > dist[node]:
                continue

            if node == n - 1:
                return time

            for neighbor, start, end in graph[node]:
                if start <= time <= end:
                    new_time = time + 1
                    if new_time < dist[neighbor]:
                        dist[neighbor] = new_time
                        heapq.heappush(pq, (new_time, neighbor))
                else:
                    wait_time = max(0, start - time)
                    new_time = time + wait_time + 1
                    if new_time < dist[neighbor]:
                        dist[neighbor] = new_time
                        heapq.heappush(pq, (new_time, neighbor))

        return -1