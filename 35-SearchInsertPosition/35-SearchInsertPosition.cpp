// Last updated: 2026/4/11 下午7:20:37
class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target)
                return i;
            else if ( nums[i] > target)
                return i;
        }
        return nums.size();
    }
};