class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        n = len(distance)
        clockwise_distance = 0
        current = start
        while current != destination:
            clockwise_distance += distance[current]
            current = (current + 1) % n
        total_distance = sum(distance)
        counterclockwise_distance = total_distance - clockwise_distance
        return min(clockwise_distance, counterclockwise_distance)