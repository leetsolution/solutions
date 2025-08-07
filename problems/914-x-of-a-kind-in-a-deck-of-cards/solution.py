class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        counts = {}
        for card in deck:
            counts[card] = counts.get(card, 0) + 1
        
        g = 0
        for count in counts.values():
            g = math.gcd(g, count)
        
        return g > 1
import math