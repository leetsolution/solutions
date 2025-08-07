class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        l_count = moves.count('L')
        r_count = moves.count('R')
        underscore_count = moves.count('_')

        return abs(r_count + underscore_count - l_count) if r_count > l_count else abs(l_count + underscore_count - r_count)