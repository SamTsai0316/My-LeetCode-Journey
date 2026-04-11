// Last updated: 2026/4/11 下午7:20:17
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];

    }
};