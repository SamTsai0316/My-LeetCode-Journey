# Last updated: 2026/10/5 下午11:39:31
1class Solution:
2    def firstUniqChar(self, s: str) -> int:
3        dic1 = {}
4        p1 = 0
5        p2 = 1
6        dic1[s[0]] = 1
7        while p2 < len(s):
8            if s[p2] == ' ':
9                continue
10            if s[p2] not in dic1:
11                dic1[s[p2]] = 1
12            else:
13                dic1[s[p2]]+=1
14            if s[p1] == ' ':
15                p1 += 1
16            while dic1[s[p1]] > 1 and p1<p2:
17                p1+=1
18            p2+=1
19        if p1 == p2-1 and dic1[s[p2-1]]>1:
20            return -1
21        return p1
22        
23"""
24用兩個 pointer 
25"""