# Last updated: 2026/10/5 下午8:46:50
1class Solution:
2    def wordPattern(self, pattern: str, s: str) -> bool:
3        dic = {}
4        s1 = s.split()
5        if len(s1) != len(pattern):
6            return False
7        for i in range(len(pattern)):
8            if pattern[i] in dic:
9                if s1[i] != dic[pattern[i]]:
10                    return False
11            else:
12                if s1[i] in dic.values():
13                    return False
14                if pattern[i] in dic:
15                    return False
16                else:
17                    dic[pattern[i]] = s1[i]
18
19        return True
20
21