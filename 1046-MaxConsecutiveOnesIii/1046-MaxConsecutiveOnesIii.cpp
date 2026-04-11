// Last updated: 2026/4/11 下午7:19:44
class Solution {
public:
    /*從頭開始用 sliding window 的方式記錄在翻轉 k 個零的情況下 最大能包含多少1*/
    int longestOnes(vector<int>& nums, int k) 
    {
        int tail = 0, head = 0;
        int currentCount = 0;
        int maxCount = 0;
        int zeroCount = 0;
        while(tail < nums.size())
        {
            
            if(nums[tail] == 0)
            {
                zeroCount++;
                if(zeroCount > k)
                {
                    while(nums[head] != 0)
                        head++;
                    head++;
                    zeroCount--;
                    currentCount = tail - head + 1;
                }
                else
                    currentCount++;
                tail++;
                
            }
            else    // nums[tail] == 1
            {
                tail++;
                currentCount++;
            }
            maxCount = max(maxCount, currentCount);
        }
        return maxCount;
    }
};