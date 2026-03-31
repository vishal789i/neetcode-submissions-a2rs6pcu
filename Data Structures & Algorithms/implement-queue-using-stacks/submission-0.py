class MyQueue:
    def __init__(self):
        self.mainStk = deque()
        self.auxStk = deque()

    def push(self, x: int) -> None:
        self.mainStk.append(x)

    def pop(self) -> int:
        if self.auxStk:
            return self.auxStk.pop()
        
        while self.mainStk:
            self.auxStk.append(self.mainStk.pop())
        
        return self.auxStk.pop()

    def peek(self) -> int:
        poppedElem = self.pop()
        self.auxStk.append(poppedElem)
        return poppedElem

    def empty(self) -> bool:
        return len(self.mainStk) == 0 and len(self.auxStk) == 0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()