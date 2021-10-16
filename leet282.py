import re
import itertools


class Solution:
    def merge(self,prev,after) -> List[str]:
        res = ""
        for u,v in zip(prev,after):
            res = res + u + v
        res += prev[-1]
        return res
    def addOperators(self, num: str, target: int):
        res = []
        operations = itertools.product(["+","-","*",""],repeat = len(num)-1)
        for op in operations:
            string = self.merge(num,op)
            if re.search("0[0-9]",string)!=None:
                continue
            try:
                if string!=num and eval(string)==target:
                    res.append(string)
            except:
                continue
        return res