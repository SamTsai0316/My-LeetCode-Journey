// Last updated: 2026/4/11 下午7:20:07
class Solution {
public:
    /*Each letter in magazine can only be used once in ransomNote. 所以不用連續只要算出現次數*/
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char, int> mp;
        for(char c:magazine)
        {
            mp[c]++;
        }
        for(char c:ransomNote)
        {
            if(mp[c] <= 0)  // 
                return 0;
            mp[c]--;
        }
        return true;
    }
};