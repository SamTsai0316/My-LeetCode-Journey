// Last updated: 2026/4/11 下午7:21:51
class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        sort(strs.begin(),strs.end());   // 因為字串是多個字幅組成，所以皆以字符為單位做排序。 e.g. ['flow','flower','flight'] -> ['flight','flow','flower']
        int n = strs.size();
        std::string ans;
        std::string first = strs[0];
        std::string last = strs[n-1]; // 排序後 第一個跟最後一個有多少相同前綴，中間的字符也會符合

        for(int i = 0 ; i< min(first.size(),last.size()); i++)
        {
            if(first[i]!=last[i])
            {
                return ans;
            }
           ans+=first[i];
        }

        return ans;

    }
};