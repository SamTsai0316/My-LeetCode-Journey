// Last updated: 2026/4/11 下午7:20:22
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
       /*這題是用 DP ，利用 prevRob 記錄前一格之前最佳的 rob value，這樣就不會有連續搶的問題，然後每次拿 prev + 當前的值 比過去所有最大*/
        int maxRob = 0;
        int prevRob = 0;
        for (int curVal : nums)
        {
            int tem = max(maxRob, prevRob + curVal);
            prevRob = maxRob;  
            maxRob = tem;
        }
        return maxRob;
    }
};