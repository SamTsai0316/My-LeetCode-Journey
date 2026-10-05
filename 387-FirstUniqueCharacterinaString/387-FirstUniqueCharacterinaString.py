# Last updated: 2026/10/5 下午11:47:07
1class Solution:
2    def firstUniqChar(self, s: str) -> int:
3        count = {}
4        for a in s:
5            count[a] = 1 + count.get(a,0)
6        for index,a in enumerate(s):
7            if count[a] == 1:
8                return index
9        return -1