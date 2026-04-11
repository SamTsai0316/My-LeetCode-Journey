// Last updated: 2026/4/11 下午7:20:24
class Solution {
public:
    /*
        1. 從中間開始找，只要中間的旁邊有更大的數，就往那半邊找，反正往大的那邊找一定找的到一個 peak
    
    
    */
    int findPeakElement(vector<int>& nums) 
    {
        int n = nums.size();
        int start = 0, end = n -1;
        while(end > start)
        {
            int mid = start + (end - start)/2;
            if(end == 1)
                return (nums[0] > nums[1])? 0 : 1;
            else if(start == n - 2)
                return (nums[n-2] > nums[n-1])? n-2 : n-1;
            else if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            else if (nums[mid] < nums[mid + 1])
                start = mid + 1;
            else if(nums[mid] < nums[mid - 1])
                end = mid - 1;
        }
        return start;
        
    }
};