// Last updated: 2026/4/11 下午7:19:58
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> count;
        int result = 0;
        int prefix = 0;
        count[0] = 1;   // 初始0要設定1，這樣第一個有符合 prefix - k = 0 的才不會算錯
        for(int num : nums)
        {
            prefix += num;
            if(count[prefix - k])
            {
                result += count[prefix - k];    // 同一個map的格子不會算過兩次，所以只加把之前出現過的都加上
            }
            count[prefix]++;
        }
        return result;
    }
};