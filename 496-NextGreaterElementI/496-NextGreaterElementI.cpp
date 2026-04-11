// Last updated: 2026/4/11 下午7:20:00
class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> res(nums1.size());
        for(int i=0 ; i < nums1.size() ; i++ )
        {
            int j = 0;
            while (nums1[i] != nums2[j] && j < nums1.size()) // 遍歷nums2看哪個相同
                j++;
            
            j++;
            while (j < nums2.size() && nums1[i] >= nums2[j]) // 看x右邊哪一個最近的比自己大
                j++;
            if (j > nums2.size()-1)
                res[i] = -1;
            else
                res[i] = nums2[j];
           
        }
        return res;
    }
};