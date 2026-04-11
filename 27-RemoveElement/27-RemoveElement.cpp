// Last updated: 2026/4/11 下午7:20:39
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int k=0;
        
        for(int i=0; i<n; i++)
        {
            if(nums[i]!=val)
            {
                nums[k]=nums[i];
                k++;
            }
            
                
        }
         return k;
    }  
};