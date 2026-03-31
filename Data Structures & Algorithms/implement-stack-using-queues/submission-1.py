class MyStack:

    def __init__(self):
        self.mainQ = deque()
        self.auxQ = deque()        

    def push(self, x: int) -> None:
        self.auxQ.append(x)
        while self.mainQ:
            self.auxQ.append(self.mainQ.popleft())
        self.mainQ, self.auxQ = self.auxQ, self.mainQ

    def pop(self) -> int:
        return self.mainQ.popleft()

    def top(self) -> int:
        return self.mainQ[0]

    def empty(self) -> bool:
        return len(self.mainQ) == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()