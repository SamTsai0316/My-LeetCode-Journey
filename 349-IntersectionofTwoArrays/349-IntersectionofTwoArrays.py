# Last updated: 2026/10/1 下午6:36:01
1class Solution:
2    def intersection(self, nums1: list[int], nums2: list[int]) -> list[int]:
3        set1 = set(nums1)
4        set2 = set(nums2)
5
6
7        return list(set1 & set2)