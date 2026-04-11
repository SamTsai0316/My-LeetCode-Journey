// Last updated: 2026/4/11 下午7:19:25
class Solution {
public:
    /*
        1. sort potions
        2. 依序檢查每一個 spell, 每一輪從 mid 開始找，大於等於 success 就更新 j，將範圍縮小到 i ~ mid-1;反之小於就更新 j ，將範圍縮小到 mid+1 ~ j
        3. 每一輪更新直到 j<i，然後回傳 m-i 就會是 "product >= success 的次數"
    
    */
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        vector<int> result;
        int n = spells.size(), m = potions.size();
        std::sort(potions.begin(), potions.end());
        for(int s = 0; s < n; s++)
        {

            int i = 0;
            int j = m-1;
            while(i <= j)
            {   
                int mid = (i+j)/2;
                long long x = (long long)spells[s] * potions[mid];    
                // 如果數vector字太大會爆開，強制讓乘法在 long long * int 型態下運算，可以防止爆開，注意這邊不能用 long     long x = spells[i] * potions[j]; 這樣還是 int 的情況下爆開
                if(x >= success)
                    j = mid-1;
                else
                    i = mid+1;
            }
            result.push_back(m-i);
        }
        return result;
    }
};