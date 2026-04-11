// Last updated: 2026/4/11 下午7:21:17
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        /*從兩端開始比較 每次記錄當下最大容量 兩端誰的高度小就往內縮(如果內層有更高的才有機會有更大容量)*/
        int maxArea = 0;
        int left = 0;
        int right = height.size()-1;

        while(left<right)
        {

            maxArea = max(maxArea , min(height[left],height[right])*(right-left) );
            if(height[left]<=height[right])
                left++;

            else
                right--;

        }
        return maxArea;    
    }
};