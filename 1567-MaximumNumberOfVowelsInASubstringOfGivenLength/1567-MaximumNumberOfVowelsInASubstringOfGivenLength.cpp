// Last updated: 2026/4/11 下午7:19:35
class Solution {
public:
    /*在字串長度為 k 的子字串中 最多有多少母音*/
    int maxVowels(string s, int k) 
    {
        int vowelsVector[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1}; // 存 a~u 後面的不用紀錄
        int  maxVowels = 0;
        for(int i = 0, currentVowels = 0; i < s.length(); i++)
        {
            currentVowels += vowelsVector[s[i] - 'a'];  // -'a' 會直接回傳該格元素的值，是母音就是 1 
            if(i >= k)    // 用滑動視窗的方式，將左邊已經不再長度k的子字串中的字移除
            {
              currentVowels -= vowelsVector[s[i-k]-'a'];    // i-k 是最左邊剛被移出子字串的字
            }
            maxVowels = max(maxVowels, currentVowels);
        }
        return maxVowels;
    }
};