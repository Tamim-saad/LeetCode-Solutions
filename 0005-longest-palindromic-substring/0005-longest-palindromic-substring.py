class Solution:
    def longestPalindrome(self, s: str) -> str:
        l=len(s)
        i=l
        while(i>=0):
            j=0
            while(j+i<=l):
                f=s[j:j+i]
                b=f[::-1]
                if(b==f):  return f
                j+=1
            i-=1
