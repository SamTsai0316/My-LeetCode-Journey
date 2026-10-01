# Last updated: 2026/10/1 下午11:08:35
1class Solution:
2    def findDisappearedNumbers(self, nums: list[int]) -> list[int]:
3        return list(set(range(1, len(nums)+1)) - set(nums))