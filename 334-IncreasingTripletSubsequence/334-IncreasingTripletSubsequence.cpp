// Last updated: 2026/4/11 下午7:20:11
class Solution {
public:
    /*找出兩個最小的，然後找出第三個就 return true，如果出現更小的 就更新原本最小的*/
    bool increasingTriplet(vector<int>& nums) 
    {
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;

        for(int n : nums)
        {
            if(n <= smallest)                // 第一層先將當前最小的放入 smallest，如果出現更小的再更新
                smallest = n;
            else if (n <= secondSmallest)    // 如果出現比 smallest 更大並且小於 secondSmallest 就會更新，如果都大於就會 return true
                secondSmallest = n ;         // 兩個 if 都要加上等於，因為出現重複的數就會跳到 return true 這是錯的
            else
                return true;
        }
        return false;
    }
};