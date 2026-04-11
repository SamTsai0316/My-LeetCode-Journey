// Last updated: 2026/4/11 下午7:19:23
class Solution 
{
public:
    string removeStars(string s) 
    {
        // 1. 利用新的字串result只要不是*就push，但遇到*就pop掉一個result的字符
        string result="";
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='*')
                result.pop_back();
            else
                result.push_back(s[i]);
        }
        return result;
    }
};