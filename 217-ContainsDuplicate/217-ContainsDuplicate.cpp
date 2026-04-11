// Last updated: 2026/4/11 下午7:20:16
class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        for(int num : nums)
            mp[num]++;
        for(auto& [key, count] : mp)    // &可以直接參考，如果不用就每一次都是複製一份
        {                               // auto& [key, count] 也可用 auto& entry，只是後面得改成 entry.second
            if(count > 1)
                return true;
        }
        return false;
    }
};