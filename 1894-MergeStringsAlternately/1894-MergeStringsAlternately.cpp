// Last updated: 2026/4/11 下午7:19:28
class Solution 
{
public:
    string mergeAlternately(string word1, string word2) 
    {
        int i =0;
        std::string result = "";
        while(i<word1.length() || i<word2.length())
        {
            if(i<word1.length())
            {
                result += word1[i];
            }
            if(i<word2.length())
            {
                result += word2[i];
            }
            i++;
       }
       
        return result;
       
    }
};