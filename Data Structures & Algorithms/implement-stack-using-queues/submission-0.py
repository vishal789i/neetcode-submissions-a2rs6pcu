class MyStack:

    def __init__(self):
        self.mainQ = deque()
        self.auxQ = deque()        

    def push(self, x: int) -> None:
        self.mainQ.append(x)

    def pop(self) -> int:
        while len(self.mainQ) > 1:
            self.auxQ.append(self.mainQ.popleft())
        
        poppedElem = self.mainQ.popleft()
        self.mainQ, self.auxQ = self.auxQ, self.mainQ
        return poppedElem

    def top(self) -> int:
        poppedElem = self.pop()
        self.mainQ.append(poppedElem)
        return poppedElem

    def empty(self) -> bool:
        return len(self.mainQ) == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()