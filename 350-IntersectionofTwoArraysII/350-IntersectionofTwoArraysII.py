# Last updated: 2026/10/1 下午10:46:35
1class Solution:
2    def intersect(self, nums1: list[int], nums2: list[int]) -> list[int]:
3        dic1 = dict(Counter(nums1))
4        dic2 = dict(Counter(nums2))
5        res = []
6        for s in dic1:
7            if s in dic2:
8                count = min(dic1[s], dic2[s])
9                res += [s]*count
10        return res
11
12