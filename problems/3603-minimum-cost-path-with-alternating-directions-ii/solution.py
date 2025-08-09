from typing import List

class Solution:
    def minCost(self, m: int, n: int, waitCost: List[List[int]]) -> int:
        import heapq
        
        cost = [[float('inf')] * n for _ in range(m)]
        cost[0][0] = 1
        
        pq = [(1, 0, 0)]
        
        while pq:
            curr_cost, row, col = heapq.heappop(pq)
            
            if curr_cost > cost[row][col]:
                continue
            
            # Move (odd steps)
            if (row, col) == (m - 1, n - 1):
                continue
                
            if (row + 1) < m:
                new_cost = curr_cost + (row + 2) * (col + 1)
                if new_cost < cost[row + 1][col]:
                    cost[row + 1][col] = new_cost
                    heapq.heappush(pq, (new_cost, row + 1, col))
                    
            if (col + 1) < n:
                new_cost = curr_cost + (row + 1) * (col + 2)
                if new_cost < cost[row][col + 1]:
                    cost[row][col + 1] = new_cost
                    heapq.heappush(pq, (new_cost, row, col + 1))
            
            # Wait (even steps)
            wait_cost_here = waitCost[row][col]
            new_cost = curr_cost + wait_cost_here
            if new_cost < cost[row][col]:
                cost[row][col] = new_cost
                heapq.heappush(pq, (new_cost, row, col))
                
        return cost[m - 1][n - 1]