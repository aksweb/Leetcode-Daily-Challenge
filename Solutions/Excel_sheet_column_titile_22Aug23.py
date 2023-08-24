class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        s=""
        n=columnNumber
        while(n>0):
            n=n-1
            ch= chr(ord('A')+ n%26)
            n//=26
            s+=ch
        # The slicing syntax [start:stop:step] allows you to reverse the string by setting step to -1
        s=s[::-1]
        return s 