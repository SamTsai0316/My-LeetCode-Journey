# Last updated: 2026/10/1 下午11:07:31
1class Solution:
2    def findDisappearedNumbers(self, nums: list[int]) -> list[int]:
3        set1 = set(nums)
4        res =[]
5        curi = 1
6        for s in range(len(nums)):
7            if curi not in set1:
8                res.append(curi)
9            curi+=1
10        return res