class Solution:
    def calPoints(self, operations: List[str]) -> int:
        stk = []
        for opr in operations:
            if opr == '+':
                stk.append(stk[-1] + stk[-2])
            elif opr == 'C':
                stk.pop()
            elif opr == 'D':
                stk.append(stk[-1] * 2)
            else:
                stk.append(int(opr))
        
        return sum(stk)