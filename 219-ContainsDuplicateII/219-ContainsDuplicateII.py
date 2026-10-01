# Last updated: 2026/10/1 下午10:23:00
1class Solution:
2    def containsNearbyDuplicate(self, nums: list[int], k: int) -> bool:
3        dic = {}
4        for i in range(len(nums)):
5            if nums[i] in dic:
6                if i-dic[nums[i]] > k:
7                    dic[nums[i]] = i
8                else:
9                    return True
10            else:
11                dic[nums[i]] = i
12        return False
13
14