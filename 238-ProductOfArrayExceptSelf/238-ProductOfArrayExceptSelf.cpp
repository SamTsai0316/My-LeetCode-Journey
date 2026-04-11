// Last updated: 2026/4/11 下午7:20:14
class Solution 
{
    
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        /*最簡單的方式是每次掃一遍 O(n^2），但如果從左邊掃一遍然後在從右邊掃一遍也可以使每一格都放入除了自己的乘積，所以O(n)*/
        vector<int> result (nums.size(),1);  // 存放最後答案
        int left =1;
        int right =1;   // left right 拿來放乘積

        // 依序將nums的乘積放入result，由左至右使result[i]放入i-1格之前所有乘積
        for(int i=0 ; i<nums.size() ; i++)
        {
            result[i]*=left;
            left*=nums[i];  // 先乘入result再更新left 才不會算到自己那個
        }
        // 由右至左使result[i]放入i+1格之後所有乘積
        for(int i=nums.size()-1 ; i>=0 ; i--)
        {
            result[i]*=right;
            right*=nums[i];
        }
        return result;

    }
};