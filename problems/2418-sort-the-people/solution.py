class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        people = []
        for i in range(len(names)):
            people.append((heights[i], names[i]))
        
        people.sort(reverse=True)
        
        result = []
        for height, name in people:
            result.append(name)
        
        return result