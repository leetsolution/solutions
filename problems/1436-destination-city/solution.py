class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        start_cities = set()
        end_cities = set()
        for path in paths:
            start_cities.add(path[0])
            end_cities.add(path[1])
        for city in end_cities:
            if city not in start_cities:
                return city
        return ""