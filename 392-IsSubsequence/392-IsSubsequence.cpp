// Last updated: 2026/4/11 下午7:20:06
class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int n=t.length();
        int m=s.length();
        int j=0;
        for(int i=0 ; i<n ; i++)
        {
            if(t[i]==s[j])
            {
                j++;
            }
        }
        if(j==m)
            return true;
        else
            return false;

    }
};