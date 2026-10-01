# Last updated: 2026/10/1 下午5:10:05
1class Solution:
2    def romanToInt(self, s: str) -> int:
3        dic = {
4            'I':1,
5            'V':5,
6            'X':10,
7            'L':50,
8            'C':100,
9            'D':500,
10            'M':1000,
11        }
12        res = 0
13        check =0
14        for i in range(len(s)):
15            a = dic[s[i]]
16            if check == 1:
17                check = 0
18                continue
19            if i == len(s)-1:
20                res += a
21                break
22            b = dic[s[i+1]]
23
24            if a<b:
25                res += (b-a)
26                check  = 1
27            else:
28                res += a
29        return res