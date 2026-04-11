// Last updated: 2026/4/11 下午7:20:19
class Solution 
{
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char,char> mp;   
        unordered_map<char,char> mp2;   // 第二個確保不會多對1 a->c, d->c

        
        for(int i = 0; i < s.length(); i++)
        {
            if(mp.find(s[i]) == mp.end() && mp2.find(t[i]) == mp2.end() )   // 確保兩邊都沒有才可插入
            {
                mp[s[i]] = t[i];
                mp2[t[i]] = s[i];

            }
            else
            {
                if(t[i] != mp[s[i]])
                    return false;
                if(s[i] != mp2[t[i]])
                    return false;
            }

        }
        return true;
    }
};