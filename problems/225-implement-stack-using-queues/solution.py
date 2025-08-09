class MyStack:

    def __init__(self):
        self.q1 = []
        self.q2 = []

    def push(self, x: int) -> None:
        self.q1.append(x)

    def pop(self) -> int:
        while len(self.q1) > 1:
            self.q2.append(self.q1.pop(0))
        res = self.q1.pop(0)
        self.q1, self.q2 = self.q2, self.q1
        return res

    def top(self) -> int:
        while len(self.q1) > 1:
            self.q2.append(self.q1.pop(0))
        res = self.q1[0]
        self.q2.append(self.q1.pop(0))
        self.q1, self.q2 = self.q2, self.q1
        return res

    def empty(self) -> bool:
        return len(self.q1) == 0