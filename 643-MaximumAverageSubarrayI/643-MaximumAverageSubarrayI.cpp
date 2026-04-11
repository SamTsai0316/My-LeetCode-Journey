// Last updated: 2026/4/11 下午7:19:56
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
       int n=nums.size();
       double temp = 0;
       double biggest=0;
       for(int j=0 ; j<k ; j++)
        {
            temp += nums[j];
        }

       biggest=temp;

       for(int i=k; i<n ; i++)
        {
            temp = temp +nums[i]-nums[i-k];
            biggest = max(biggest,temp);  
        }
       
       return biggest/k;     
    }
};