class Solution:
    import heapq

    def is_prime(n):
        if n <= 1:
            return False
        i = 2
        while i * i <= n:
            if n % i == 0:
                return False
            i += 1
        return True

    def minJumps(nums):
        n = len(nums)
        if n <= 1:
            return 0

        graph = {i: [] for i in range(n)}
        for i, num in enumerate(nums):
            if i > 0:
                graph[i].append(i - 1)
            if i < n - 1:
                graph[i].append(i + 1)
            if is_prime(num):
                for j, other_num in enumerate(nums):
                    if i != j and other_num % num == 0:
                        graph[i].append(j)

        dist = {i: float('inf') for i in range(n)}
        dist[0] = 0
        pq = [(0, 0)]

        while pq:
            d, u = heapq.heappop(pq)
            if d > dist[u]:
                continue
            if u == n - 1:
                return d
            for v in graph[u]:
                if dist[v] > dist[u] + 1:
                    dist[v] = dist[u] + 1
                    heapq.heappush(pq, (dist[v], v))
        return -1