// Last updated: 2026/4/11 下午7:19:51
class Solution 
{
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        for(int i=cost.size()-3 ; i>=0 ; i--)
        {
           cost[i]+=min(cost[i+1],cost[i+2]);
        }
        return min(cost[0],cost[1]);
    }
};
/*
1. 從頭開始記錄會有太多種走法，更何況可以從index 0 or 1 開始
2. 所以從尾部開始往前算，一次跳一個 一次比較兩格(因為只能跳兩步)選出最小
3. 並將最小的加入該格 -> 每次選到的最小的cost加上之前的就是從該點到終點的的最小cost
each cost indicates that they are total costs from each postion to the goal position
4. 最後return cost 0 or 1 就可以知道哪個是最小
(如果是另外用result+=則可能會出現多加情況，因為題目是可以從0 or 1開始)

   
   


*/