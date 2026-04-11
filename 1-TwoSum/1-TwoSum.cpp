// Last updated: 2026/4/11 下午7:21:14
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(); 
        for (int i=0; i<n; i++ ){
            for (int j=i+1; j<n; j++ ){
                 if (nums[i] + nums[j] == target){

                    return {i,j};
                    break;
                }
    
            }
        }    
        return {};
    }
};