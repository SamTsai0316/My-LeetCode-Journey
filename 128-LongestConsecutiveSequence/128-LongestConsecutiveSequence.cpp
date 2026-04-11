// Last updated: 2026/4/11 下午7:20:28
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> mp = {nums.begin(), nums.end()}; // 每 sort 過
        int larg = 0;
        for(int n : mp)
        {
            if(mp.find(n-1) == mp.end())    // 找前面那一個，如果找不到 find 會停在 end
            {                               // 這邊目的是跳過那些不是 substring 頭的數字，所以不是頭的都會跳過
                int curNum = n;
                int curCount = 1;           
                while(mp.find(curNum+1) != mp.end())    // while loop 找到該substring 長度
                {
                    curNum++;
                    curCount++;
                }
                larg = max(larg, curCount);
            }
        }
        return larg;
    }
};