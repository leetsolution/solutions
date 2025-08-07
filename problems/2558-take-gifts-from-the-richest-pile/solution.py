class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        import heapq
        heap = [-x for x in gifts]
        heapq.heapify(heap)
        for _ in range(k):
            curr = heapq.heappop(heap)
            heapq.heappush(heap, -int(math.sqrt(-curr)))
        return -sum(heap)
import math