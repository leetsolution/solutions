class MyHashMap:

    def __init__(self):
        self.size = 1000
        self.table = [[] for _ in range(self.size)]

    def put(self, key: int, value: int) -> None:
        index = key % self.size
        for i, (k, v) in enumerate(self.table[index]):
            if k == key:
                self.table[index][i] = (key, value)
                return
        self.table[index].append((key, value))

    def get(self, key: int) -> int:
        index = key % self.size
        for k, v in self.table[index]:
            if k == key:
                return v
        return -1

    def remove(self, key: int) -> None:
        index = key % self.size
        for i, (k, v) in enumerate(self.table[index]):
            if k == key:
                del self.table[index][i]
                return