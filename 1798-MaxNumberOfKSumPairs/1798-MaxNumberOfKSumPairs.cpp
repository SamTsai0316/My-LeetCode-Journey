// Last updated: 2026/4/11 下午7:19:30
class Solution 
{
public:
    int maxOperations(vector<int>& nums, int k) 
    {
        int resultCount = 0;
        int i=0;
        int j=nums.size()-1;
        sort(nums.begin(), nums.end());
        // 用頭尾往中間的方法，可以不用計算已經用過的pair，因為已經sort，假設 nums[i]+nums[j] < k 那代表i之前的元素都不會有符合資格的
        while(i<j)
        {
            if(nums[i]+nums[j] > k)
                j--;
            else if(nums[i]+nums[j] < k)    
                i++;
            else
            {
                resultCount++;
                i++;
                j--;    // 因為吻合 所以nums[i]、nums[j]都不能再用
            }
        }
        return resultCount;
    }
};