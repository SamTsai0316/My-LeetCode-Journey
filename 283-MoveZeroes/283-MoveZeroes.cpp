// Last updated: 2026/4/11 下午7:20:13
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int n=nums.size();
        int j=0;
        for(int i =0 ; i<n ; i++)
        {
            if (nums[i]!=0)
            {
                swap(nums[i],nums[j]);
                j++;
            }
        } 
       
    }
};